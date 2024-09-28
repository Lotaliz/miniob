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

using namespace std;

UpdatePhysicalOperator::UpdatePhysicalOperator(
  Table *table, FieldMeta *field, Value *value)
  : table_(table), field_(field), value_(value)
{}

RC UpdatePhysicalOperator::open(Trx *trx)
{
  Record record;
  RC     rc = table_->set_value_to_record(nullptr, *value_, field_);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to update record. rc=%s", strrc(rc));
    return rc;
  }

  rc = trx->delete_record(table_, record);
  if(rc != RC::SUCCESS){
    LOG_WARN("failed to update record by transaction. rc=%s", strrc(rc));
  }
  rc = trx->insert_record(table_, record);
  if(rc != RC::SUCCESS){
    LOG_WARN("failed to update record by transaction. rc=%s", strrc(rc));
  }
  return rc;
}

RC UpdatePhysicalOperator::next() { return RC::RECORD_EOF; }

RC UpdatePhysicalOperator::close() { return RC::SUCCESS; }
