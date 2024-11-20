/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "common/lang/comparator.h"
#include "common/log/log.h"
#include "common/type/char_type.h"
#include "common/value.h"
#include "common/lang/sstream.h"

class DateType;

int CharType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::CHARS && right.attr_type() == AttrType::CHARS, "invalid type");
  return common::compare_string(
      (void *)left.value_.pointer_value_, left.length_, (void *)right.value_.pointer_value_, right.length_);
}

RC CharType::set_value_from_str(Value &val, const string &data) const
{
  val.set_string(data.c_str());
  return RC::SUCCESS;
}

RC CharType::cast_to(const Value &val, AttrType type, Value &result) const
{
  RC rc = RC::SUCCESS;
  const string &data = val.get_string();
  std::istringstream dateStream(data);
  uint32_t date_int = 0;
  switch (type) {
    case AttrType::DATE:
      int year, month, day;
      char dash1, dash2;
      dateStream >> year >> dash1 >> month >> dash2 >> day;
      date_int |= (day & 0xFF); 
      date_int |= (month & 0xFF) << 8;    
      date_int |= ((year - 1970) & 0xFF) << 16; 
      result.set_int(date_int);
      result.set_type(AttrType::DATE);
      break;

    default: return RC::UNIMPLEMENTED;
  }
  return rc;
}

int CharType::cast_cost(AttrType type)
{
  switch(type){
    case AttrType::CHARS:
      return 0;
    case AttrType::INTS:
      return 1;
    case AttrType::FLOATS:
      return 2;
    case AttrType::DATE:
      return 3;
    default: return INT32_MAX;
  }
  // if (type == AttrType::NULLS) {
  //   return 4;
  // }
  return INT32_MAX;
}

RC CharType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << val.value_.pointer_value_;
  result = ss.str();
  return RC::SUCCESS;
}