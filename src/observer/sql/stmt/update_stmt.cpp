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
// Created by Wangyunlai on 2022/5/22.
// Modified by Lotaliz Sep.22, 2024

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

UpdateStmt::UpdateStmt(Table *table, Value *values, int value_amount)
    : table_(table), values_(values), value_amount_(value_amount)
{}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name.c_str();
  const char *attribute_name = update.attribute_name.c_str();
  if (nullptr == db || nullptr == table_name || update.attribute_name.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, attribute_name=%p",
        db, table_name, update.attribute_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // check whether the field exists
  const TableMeta &table_meta = table->table_meta();
  const FieldMeta *field_meta = table_meta.field(attribute_name);
  if(nullptr == field_meta){
    LOG_WARN("no such field. db=%s, field=%s", db->name(), attribute_name);
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  

  // stmt = new UpdateStmt(table, values, value_amount);
  return RC::INTERNAL;
}
