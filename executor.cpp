#include "executor.h"
#include "filesystem.h"

#include "commondef.h"

#include "string"
#include "iostream"
using namespace std;


ExecuteExamples::ExecuteExamples()
{
}

ExecuteExamples::~ExecuteExamples()
{
}

void ExecuteExamples::do_examples()
{
	cout << "enter do_examples" << endl;
	do_filesystem();
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