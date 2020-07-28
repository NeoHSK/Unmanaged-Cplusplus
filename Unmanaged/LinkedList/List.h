#pragma once

template <class T>
class List
{
public:
	virtual void Insert(const T& Data) = 0;
	virtual void Remove(const T& Data) = 0;
	virtual void TraverseList() = 0;
	virtual int size() const  = 0;
};
