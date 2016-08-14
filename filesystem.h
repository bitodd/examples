#ifndef FILESYSTEM_h__
#define FILESYSTEM_h__

#include "string"

class FileSystem
{
public:
	FileSystem();
	~FileSystem();
	//grab a signal line of data from the file
	std::string getFileLineContent(const std::string& filepath);
	//grab all data from the file
	std::string getFileContent(const std::string& filepath);

private:

};


#endif // FILESYSTEM_h__
