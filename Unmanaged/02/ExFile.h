#pragma once
#include <iostream>
#include <string>

struct Record
{
	std::string FirstName;
	std::string LastName;
	std::string StudentID;
	std::string Score;
};
class ExFile
{
public:
	ExFile() {};
	~ExFile() {};
	
	Record ReadRecord(std::istream& stream, bool bPrompt);
	void WriteRecord(std::fstream& fileStream, const Record& record);
	void Show(std::fstream& filesStream);
	void run();
protected:

private:

};

