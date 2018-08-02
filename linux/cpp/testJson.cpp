#include<json/json.h>
#include<iostream>
using namespace std;


const std::string test_json_str = "\{\"device\":\"UNIBOMAC\",\"cmd\":\"register\",\"type\":5,\"sequence\":1527584393223,\"info\":\{\"error\":0\}\}";

Json::Value str2Json(const std::string& str)
{
    Json::Reader reader;
    Json::Value value;
    if(!reader.parse(str, value))
    {
        cout<<"parser error"<<endl;
        return value;
    }
    cout<<"devive:"<<value["device"]<<endl;
    cout<<"info error:"<<value["info"]["error"]<<endl;
    return value;
}

int main(int argc, char** argv)
{
#if 0
    Json::Value root;
    Json::FastWriter fast;
    root["ModuleType"]= Json::Value("你好");
    root["ModuleCode"]= Json::Value("22");
    root["ModuleDesc"]= Json::Value("33");
    root["DateTime"]= Json::Value("44");
    root["LogType"]= Json::Value("55");
    cout<<fast.write(root)<<endl;
#else
    Json::Value value;
    value = str2Json(test_json_str);

#endif

    return 0;
}
