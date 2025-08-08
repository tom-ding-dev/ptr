#include "mylib/json_utils.h"
#include <json/json.h>
#include <vector>

namespace mylib {

Json::Value personToJson(const Person& p) {
    Json::Value v;
    v["name"] = p.getName();
    v["age"] = p.getAge();
    return v;
}

Person personFromJson(const Json::Value& v) {
    return Person(v["name"].asString(), v["age"].asInt());
}

Json::Value studentToJson(const Student& s) {
    Json::Value v = personToJson(s);
    Json::Value courses(Json::arrayValue);
    for (const auto& c : s.getCourses()) {
        courses.append(c);
    }
    v["courses"] = courses;
    return v;
}

Student studentFromJson(const Json::Value& v) {
    std::vector<std::string> courses;
    for (const auto& c : v["courses"]) {
        courses.push_back(c.asString());
    }
    return Student(v["name"].asString(), v["age"].asInt(), courses);
}

} // namespace mylib
