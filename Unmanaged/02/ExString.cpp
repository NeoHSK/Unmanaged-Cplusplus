#include <iostream>
#include <string>
#include <sstream>
#include "ExString.h"

using namespace std;

void ExString::Mirror()
{
	cout << "	----	Ex Mirror	----	" << endl;

	string tests = "Hello world";
	/*	capacity 증가 */
	tests.reserve(50);

	cout <<	"	before mirrored	" << endl;
	cout <<		tests << endl;

	cout << "	after mirrored	" << endl;

	string tests_mirror;
	/* resize 하지 않으면 에러 발생	*/
	tests_mirror.resize(tests.size());
	size_t itend = tests.size()-1;
	for (size_t i = 0; i <= itend; i++)
	{
		tests_mirror[i] = tests[itend -i];
	}
	
	cout <<		tests_mirror << endl;
}

void ExString::Stream()
{
	string name;
	size_t num;
	string id;
	size_t nhex;
	istringstream istr("Neo 123 A123 0x33");
	ostringstream ostr;

	istr >>	name >>	num >> id >> nhex;
	cout << "	----	Ex Stream	----	" << endl;
	cout << name << " " << num << " " << id << endl;
	//cout << std::hex<<nhex<< endl;

}
