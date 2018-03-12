#include "filesystem.h"
#include "commondef.h"

#include <iostream>
#include <fstream>
#include "windows.h"
#include <iostream>
using namespace std;

FileSystem::FileSystem()
{
}
FileSystem::~FileSystem()
{
}

std::string FileSystem::getFileLineContent(const std::string& filepath)
{
  cout << "getContent from this file="<<filepath << endl;
  std::string content = "";
  FILE* fp = nullptr;
  char* buf= new char[MAX_CONTENT_LEN];
  memset(buf, 0, MAX_CONTENT_LEN);
  char* p = nullptr;
  int errorcode = fopen_s(&fp,filepath.c_str(), "r");
  if(errorcode != 0 )
  {
    cout << "open file error,errorcode="<<errorcode << endl;
    return content;
  }
  p = fgets(buf, MAX_CONTENT_LEN, fp);
  if (!p)
  {
    cout << "get file content error" << endl;
    return content;
  }
  //strncpy_s(content, MAX_CONTENT_LEN, buf, MAX_CONTENT_LEN);
  content = buf;
  delete []buf;
  buf = nullptr;
  return content;
}

std::string FileSystem::getFileContent(const std::string& filepath)
{
  std::ifstream stream(filepath.c_str(), std::ios::in);
  istreambuf_iterator<char> beg(stream), end;
  std::string content(beg, end);
  stream.close();
  return content;
}
