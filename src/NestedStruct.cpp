#include "nestedstruct.h"

basevec* NestedStruct::getTeamInfo()
{
  basevec* vec = new basevec;
  team* ml = new team;
  ml->id = "1001";
  ml->teamName = "cppgroup";
  for (auto i = 0; i < 1; ++i)
  {
    student* stu = new student;
    stu->age = 19;
    strcpy_s(stu->name, 10, "javep");
    ml->data.push_back(stu);
  }
  vec->push_back(ml);
  return (basevec*)vec;
}

void NestedStruct::showStructData()
{
  basevec* vec = new basevec;
  vec = getTeamInfo();

  if (vec->size() > 0)
  {
    for (auto itr = vec->begin(); itr != vec->end(); ++itr)
    {
      auto b = (team*)*itr;
      auto id = b->id;
      auto teamname = b->teamName;
      auto stu_struct = b->data;
      cout << "id=" << id << ",team name=" << teamname << endl;
      for (auto itr = stu_struct.begin(); itr != stu_struct.end(); ++itr)
      {
        cout << "team member:" << " name=" << (*itr)->name << " ,age=" << (*itr)->age << endl;
      }

    }
  }
}