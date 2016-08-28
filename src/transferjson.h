#ifndef TRANSFERJSON_h__
#define TRANSFERJSON_h__

#include "json/json.h"
#include "string"

//class Json;

class JsonTransfer
{
public:
  JsonTransfer();
  ~JsonTransfer();
  Json::Value StrToJson(const std::string& str);
  std::string JsonToStr(const Json::Value& jsonvalue);

private:

};



#endif // TRANSFERJSON_h__