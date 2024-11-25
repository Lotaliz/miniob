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

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/date_type.h"
#include "common/value.h"
#include <iomanip>

int DateType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::DATE, "left type is not date");
  if(right.attr_type() == AttrType::NULLS)
    return INT32_MIN;

  ASSERT(right.attr_type() == AttrType::DATE, "right type is not date");
  
  if(get_year(left) > get_year(right)) return 1;
  else if(get_year(left) < get_year(right)) return -1;
  if(get_month(left) > get_month(right)) return 1;
  else if(get_month(left) < get_month(right)) return -1;
  if(get_day(left) > get_day(right)) return 1;
  else if(get_day(left) < get_day(right)) return -1;
  return 0;
}

RC DateType::set_value_from_str(Value &val, const string &data) const
{
  RC rc = RC::SUCCESS;
  int year, month, day;
  char dash1, dash2;
  std::istringstream dateStream(data);
  dateStream >> year >> dash1 >> month >> dash2 >> day;

  uint32_t result = 0;
  result |= (day & 0xFF); 
  result |= (month & 0xFF) << 8;    
  result |= ((year - 1970) & 0xFF) << 16; 

  val.set_int(result);
  return rc;
}

RC DateType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  uint32_t int_date = val.value_.int_value_;
  int day = int_date & 0xFF; 
  int month = (int_date >> 8) & 0xFF; 
  int year = ((int_date >> 16) & 0xFF) + 1970; 

  // Format the date string as "YYYY-MM-DD"
  std::ostringstream dateStream;
  dateStream << year << '-' 
             << std::setw(2) << std::setfill('0') << month << '-'
             << std::setw(2) << std::setfill('0') << day;

  result = dateStream.str();
  return RC::SUCCESS;
}