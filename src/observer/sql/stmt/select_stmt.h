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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <memory>
#include <vector>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

struct FilterObj
{
  bool  is_attr;
  Field field;
  Value value;
  void init_attr(const Field &field)
  {
    is_attr     = true;
    this->field = field;
  }
  void init_value(const Value &value)
  {
    is_attr     = false;
    this->value = value;
  }
};

class FilterUnit
{
public:
  FilterUnit() = default;
  ~FilterUnit() {}
  void set_comp(CompOp comp) { comp_ = comp; }
  CompOp comp() const { return comp_; }
  void set_left(const FilterObj &obj) { left_ = obj; }
  void set_right(const FilterObj &obj) { right_ = obj; }
  const FilterObj &left() const { return left_; }
  const FilterObj &right() const { return right_; }
private:
  CompOp    comp_ = NO_OP;
  FilterObj left_;
  FilterObj right_;
};

class TableUnit
{
public:
  TableUnit() = default;
  ~TableUnit() {}
  Table *table() { return table_; }
  const std::vector<FilterUnit *> &filter_units() const { return filter_units_; }
  void set_table(Table *table) { table_ = table; }
  void add_filter_unit(FilterUnit *filter_unit) { filter_units_.push_back(filter_unit); }
private:
  Table                     *table_;
  std::vector<FilterUnit *> filter_units_;
};

/**
 * @brief 表示select语句
 * @ingroup Statement
 */
class SelectStmt : public Stmt
{
public:
  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }

public:
  static RC create(Db *db, SelectSqlNode &select_sql, Stmt *&stmt);

public:
  const std::vector<TableUnit *> &table_units() const { return table_units_; }
  FilterStmt                     *filter_stmt() const { return filter_stmt_; }

  std::vector<std::unique_ptr<Expression>> &query_expressions() { return query_expressions_; }
  std::vector<std::unique_ptr<Expression>> &group_by() { return group_by_; }

private:
  std::vector<std::unique_ptr<Expression>> query_expressions_;
  std::vector<TableUnit *>                 table_units_;
  FilterStmt                              *filter_stmt_ = nullptr;
  std::vector<std::unique_ptr<Expression>> group_by_;
};
