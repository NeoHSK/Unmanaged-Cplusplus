#include <iostream>
#include <string>
#include "ExMString.h"

ExMString::ExMString()
{
}

ExMString::ExMString(const char* str)
	:mSize(strlen(str)+1)
{
	mString = new char[mSize];
	memcpy(mString, str, mSize);
}

ExMString::ExMString(const ExMString& str)
	:mSize(str.mSize)
{
	mString = new char[mSize];
	memcpy(mString, str.mString, mSize);
}

ExMString::~ExMString()
{
	delete[] mString;
}

void ExMString::Print()
{
	std::cout << "	----	Name	----	" << mString<< std::endl;

}

void ExMString::Run()
{
	std::cout << "	----	Ex Stream	----	" << std::endl;

	ExMString Name("Neo Kim");
	ExMString copyName(Name);
	
	Name.Print();
	copyName.Print();

	delete Name;
}
