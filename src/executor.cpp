#include "executor.h"
#include "filesystem.h"
#include "transferjson.h"

#include "commondef.h"

#include "string"
#include "iostream"
using namespace std;

#ifdef WIN32
#include "windows.h"
#endif

ExecuteExamples::ExecuteExamples()
{
}

ExecuteExamples::~ExecuteExamples()
{
}

void ExecuteExamples::showAllExamples()
{
  system("cls");
  cout << "----------------------all the examples--------------------------" << endl;
  cout << "------------------------1.filesystem----------------------------" << endl;
  cout << "------------------------2.json and string-----------------------" << endl;
  cout << "---------------Please select which example to show----------------" << endl;
  int number;
  cin >> number;
  if (number>0 && 9>number)
  {
    do_examples(number);
    cout << "show these examples again?(y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      showAllExamples();
    }
    else
    {
      cout << "quiting" << endl;
    }
  }
}

void ExecuteExamples::do_examples(int sequence)
{
  switch (sequence)
  {
  case 1:
    do_filesystem();
    break;
  case 2:
    transferToJson();
    break;
  default:
    break;
  }
}

void ExecuteExamples::do_filesystem()
{
  FileSystem* fs = new FileSystem;
  std::string singlecontent = fs->getFileLineContent(FILE_PATH);
  cout << "first line of data:" << endl << singlecontent << endl;
  std::string allcontent = fs->getFileContent(FILE_PATH);
  cout << "all content:" << endl << allcontent << endl;
  return;
}
void ExecuteExamples::transferToJson()
{
  Json::Value value;
  JsonTransfer* ts = new JsonTransfer;
  cout << "string------>json" << endl;
  char* test_str = "{\"age\":\"26\",\"name\":\"brant\"}";
  value = ts->StrToJson(test_str);
  cout << "json-------->string" << endl;
  ts->JsonToStr(value);
}