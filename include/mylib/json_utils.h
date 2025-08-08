#ifndef MYLIB_JSON_UTILS_H
#define MYLIB_JSON_UTILS_H

#include <json/json.h>
#include "mylib/person.h"
#include "mylib/student.h"

namespace mylib {

Json::Value personToJson(const Person& p);
Person personFromJson(const Json::Value& v);

Json::Value studentToJson(const Student& s);
Student studentFromJson(const Json::Value& v);

} // namespace mylib

#endif // MYLIB_JSON_UTILS_H
