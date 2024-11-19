/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

// created by Lotaliz on 2024/11/11

#pragma once

#include "common/type/data_type.h"
#include "common/value.h"

class DateType : public DataType
{
public:
  DateType() : DataType(AttrType::DATE) {}
  virtual ~DateType() = default;

  int compare(const Value &left, const Value &right) const override;
  RC set_value_from_str(Value &val, const string &data) const override;
  RC to_string(const Value &val, string &result) const override;
  int get_year(const Value &val) const { return (val.value_.int_value_ >> 16) & 0xFF; }
  int get_month(const Value &val) const { return (val.value_.int_value_ >> 8) & 0xFF; }
  int get_day(const Value &val) const { return val.value_.int_value_  & 0xFF; }
};