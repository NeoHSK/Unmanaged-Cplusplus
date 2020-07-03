#include <fstream>
#include <iomanip>
#include "ExFile.h"

Record ExFile::ReadRecord(std::istream& stream, bool bPrompt)
{
	Record record;

	if (bPrompt)
	{
		std::cout << "First name: " ;
	}
	stream >> record.FirstName;

	if (bPrompt)
	{
		std::cout << "Last name: " ;
	}
	stream >> record.LastName;

	if (bPrompt)
	{
		std::cout << "Strudent ID: " ;
	}
	stream >> record.StudentID;

	if (bPrompt)
	{
		std::cout << "Score: " ;
	}
	stream >> record.Score;

	return record;
}

void ExFile::WriteRecord(std::fstream& fileStream, const Record& record)
{
	fileStream.seekp(0, std::ios_base::end);

	fileStream << record.FirstName << " "
		<< record.LastName << " "
		<< record.Score << " "
		<< record.StudentID << std::endl;
	
	fileStream.flush();
}

void ExFile::Show(std::fstream& filesStream)
{
	filesStream.seekg(0);

	std::string line;

	while (true)
	{
		std::getline(filesStream, line);

		if (filesStream.eof())
		{
			filesStream.clear();
			break;
		}
		
		std::cout << line << std::endl;

	}
}

void ExFile::run()
{
	std::cout << "	----	Ex File		----	" << std::endl;

	std::fstream fileStream;
	bool bExit = false;

	fileStream.open("studentRecords.dat",std::ios_base::in | std::ios_base::end);

	if (fileStream.is_open() == false)
	{
		fileStream.clear();
		fileStream.open("studentRecords.dat", std::ios_base::out);

	}
	
	while (bExit == false)
	{
		char command = ' ';

		std::cout << "a: add" << std::endl
			<< "d: display" << std::endl
			<< "x: exit" << std::endl;

		std::cin >> command;
		std::cin.ignore(LLONG_MAX, '\n');

		switch (command)
		{
			case 'a':
			{
				Record record = ReadRecord(std::cin, true);
				WriteRecord(fileStream, record);
			}
				break;

			case 'd':
			{
				Show(fileStream);
			}
				break;

			case 'x':
			{
				bExit = true;
			}
				break;

			default:
			{
				std::cout << "invalid input" << std::endl;

			}
				break;
		}
	}

	fileStream.close();
}


