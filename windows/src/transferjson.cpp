#include "transferjson.h"
#include "iostream"
using namespace std;

JsonTransfer::JsonTransfer()
{
}
JsonTransfer::~JsonTransfer()
{
}

// reference type should not return a temporary string

std::string JsonTransfer::JsonToStr(const Json::Value& jsonvalue)
{
  std::string str = "";
  std::string name = "";
  std::string age = "";
  if (jsonvalue.isMember("name"))
  {
    name = jsonvalue["name"].asString();
  }
  if (jsonvalue.isMember("age"))
  {
    age = jsonvalue["age"].asString();
  }
  cout << "name:"<<name<<",age:"<<age << endl;
  str.append(name).append(":").append(age);
  cout << str << endl;
  return str;
}

Json::Value JsonTransfer::StrToJson(const std::string& str)
{
  Json::Reader reader;
  Json::Value value;
  cout << "str="<<str << endl;

  if (!reader.parse(str, value))
  {
    cout << "parser error" << endl;
    return value;
  }
  cout << "name="<<value["name"] << endl;
  cout << "age=" << value["age"] << endl;
  return value;
}