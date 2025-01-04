/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2021/6/9.
//

#include "sql/operator/insert_physical_operator.h"
#include "sql/stmt/insert_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

using namespace std;

InsertPhysicalOperator::InsertPhysicalOperator(Table *table, std::vector<std::vector<Value> > &&rows)
    : table_(table), rows_(std::move(rows))
{}

RC InsertPhysicalOperator::open(Trx *trx)
{
  RC rc = RC::SUCCESS;
  vector<Record> records;
  records.resize(rows_.size());
  for(int i = 0; i < rows_.size(); i++) {
    Record &temp_record = records[i];
    rc = table_->make_record(static_cast<int>(rows_[i].size()), rows_[i].data(), temp_record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to make record. rc=%s", strrc(rc));
      for (int j = i - 1; j >= 0; j--) {
        Record &inserted_record = records[j];
        RC rc2 = trx->delete_record(table_, inserted_record);
        if (rc2 != RC::SUCCESS) {
          LOG_WARN("failed to rollback falsely inserted records. rc=%s", strrc(rc2));
          break;
        }
      }
      return rc;
    }
    rc = trx->insert_record(table_, temp_record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record by transaction. rc=%s", strrc(rc));
      return rc;
    }
  }
  return rc;
}

RC InsertPhysicalOperator::next() { return RC::RECORD_EOF; }

RC InsertPhysicalOperator::close() { return RC::SUCCESS; }
