#pragma once

class ExMString
{
public:
	ExMString();
	ExMString(const char* str);
	ExMString(const ExMString& str);
	~ExMString();

	void Print();
	void Run();

protected:

private:
	char* mString;
	size_t mSize;
};

