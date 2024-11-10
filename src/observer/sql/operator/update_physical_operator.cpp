/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

// created by Lotaliz on 2024/9/28.

#include "sql/operator/update_physical_operator.h"
#include "sql/stmt/update_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"
#include "common/value.h"

using namespace std;

UpdatePhysicalOperator::UpdatePhysicalOperator(
  Table *table, FieldMeta *field, Value *value)
  : table_(table), field_(field), value_(value)
{}

RC UpdatePhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  std::unique_ptr<PhysicalOperator> &child = children_[0];

  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  while (OB_SUCC(rc = child->next())) {
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record   &record    = row_tuple->record();
    records_.emplace_back(std::move(record));
  }
  child->close();

  for (Record &record : records_) {
    vector<char> tmp_record(table_->table_meta().record_size());
    memcpy(tmp_record.data(), record.data(), tmp_record.size());
    rc = trx_->delete_record(table_, record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    }
    deleted_records_.emplace_back(tmp_record);
  }

  for(int i = 0; i < deleted_records_.size(); i++){
    RID rid;
    rc = update(deleted_records_[i], field_, value_, rid);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record: %s", strrc(rc));
      return rc;
    }
  }
  return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next() { return RC::RECORD_EOF; }

RC UpdatePhysicalOperator::close() { return RC::SUCCESS; }

RC UpdatePhysicalOperator::update(vector<char> record, FieldMeta *field, Value *value, RID &rid) {
  const FieldMeta *fieldmeta = field;
  if (value->attr_type() != fieldmeta->type()) {
    // TODO: nullable test
    // TODO: convert attr_type
    // if (!Value::convert(value.attr_type(), fieldmeta->type(), value)) {
    //   line_sql_debug("rc=%s", strrc(RC::INVALID_ARGUMENT));
    //   LOG_WARN("failed to convert update value");
    //   return RC::INVALID_ARGUMENT;
    // }
  }
  int offset = fieldmeta->offset();
  if (fieldmeta->type() != AttrType::CHARS) {
    memcpy(record.data() + offset, value, 4);
  } else {
    if (value->length() > fieldmeta->len()) {
      LOG_WARN("rc=%s", strrc(RC::INVALID_ARGUMENT));
      return RC::INVALID_ARGUMENT;
    }
    memcpy(record.data() + offset, value->data(), value->length());
    memset(record.data() + offset + value->length(), 0, fieldmeta->len() - value->length());
  }
    
  return insert(record, rid);
}

RC UpdatePhysicalOperator::insert(vector<char> &record_data, RID &rid) {
  Record record;
  RC rc = table_->make_record(record_data.data(), record_data.size(), record);
  if (rc != RC::SUCCESS) {
    LOG_WARN("rc=%s", strrc(rc));
    LOG_ERROR("fail to make record");
    return rc;
  }
  rc = trx_->insert_record(table_, record);
  if (rc != RC::SUCCESS) {
    LOG_WARN("rc=%s", strrc(rc));
    LOG_ERROR("fail to insert record");
    return rc;
  }
  rid = record.rid();
  return rc;
}