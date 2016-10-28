#pragma once
#include "string"
#include "vector"
#include "list"
#include "iostream"
using namespace std;

class base
{
public:

};
typedef vector<base*> basevec;

struct student
{
  char name[10];
  short age;
  student() { memset(name, 0, 10); }
};

class team : public base
{
public:
  char* id;
  char* teamName;
  list<student*> data;
  team() :id(nullptr), teamName(nullptr) {}
};

class NestedStruct
{
public:
  basevec* getTeamInfo();
  void showStructData();
};