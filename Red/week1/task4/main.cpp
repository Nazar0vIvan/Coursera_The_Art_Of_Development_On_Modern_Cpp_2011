#include <algorithm>
#include <numeric>
#include <ostream>
#include <iomanip>

#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

bool operator<(const Time& lhs, const Time& rhs){
  if (lhs.hours != rhs.hours){
    return lhs.hours < rhs.hours;
  }
  return lhs.minutes < rhs.minutes;
}

bool operator==(const Time& lhs, const Time& rhs){
  return (lhs.hours == rhs.hours && lhs.minutes == rhs.minutes);
}

bool operator<(const Date& lhs, const Date& rhs){
  if (lhs.year != rhs.year){
    return lhs.year < rhs.year;
  }
  if (lhs.month != rhs.month){
    return lhs.month < rhs.month;
  }
  return lhs.day < rhs.day;
}

bool operator==(const Date& lhs, const Date& rhs){
    return (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day);
}

istream& operator>>(istream& is, Date& date)
{
  is >> date.year;
  is.ignore(1);
  is >> date.month;
  is.ignore(1);
  is >> date.day;
  return is;
}

istream& operator>>(istream& is, Time& time)
{
  is >> time.hours;
  is.ignore(1);
  is >> time.minutes;
  return is;
}

ostream& operator<<(ostream& os, const Date& date)
{
  os << std::setfill('0') << std::setw(4) << std::to_string(date.year);
  os << "-";
  os << std::setfill('0') << std::setw(2) << std::to_string(date.month);
  os << "-";
  os << std::setfill('0') << std::setw(2) << std::to_string(date.day);
  return os;
}

ostream& operator<<(ostream& os, const Time& time)
{
  os << std::setfill('0') << std::setw(2) << std::to_string(time.hours);
  os << ":";
  os << std::setfill('0') << std::setw(2) << std::to_string(time.minutes);
  return os;
}

#define UPDATE_FIELD(ticket, field, values)({ \
  auto it = values.find(#field);              \
  if(it != values.end()){                     \
    istringstream is(it->second);             \
    is >> ticket.field;                       \
  }                                           \
})

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {{"departure_date", "2018-2-28"},{"departure_time", "17:40"}};
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {{"price", "12550"},{"arrival_time", "20:33"}};
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
