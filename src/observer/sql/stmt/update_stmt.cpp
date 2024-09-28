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

UpdateStmt::UpdateStmt(Table *table, const FieldMeta *field, const Value *value,
  FilterStmt* filter)
  : table_(table), field_(field), value_(value), filter_(filter)
{}

UpdateStmt::~UpdateStmt()
{
  delete(filter_);
}

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
  const FieldMeta *field = table_meta.field(attribute_name);
  if(nullptr == field){
    LOG_WARN("no such field. db=%s, field=%s", db->name(), attribute_name);
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  // check field type matching
  const Value *value = &update.value;
  if(value->attr_type() != field->type()){
    LOG_WARN("field type mismatch. table=%s, field=%s, field_type=%d, value_type=%d",
    table->name(), attribute_name, field->type(), value->attr_type());
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  
  unordered_map<string, Table*> table_map;
  table_map.insert(pair<string, Table*>(string(table_name), table));
  FilterStmt* filter = nullptr;
  RC rc = FilterStmt::create(db, table, &table_map, update.conditions.data(),
     update.conditions.size(), filter);
  if(rc != RC::SUCCESS){
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  stmt = new UpdateStmt(table, field, value, filter);
  return RC::SUCCESS;
}
