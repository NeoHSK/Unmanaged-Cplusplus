#include <iostream>
#include "MVector.h"

MVector::MVector()
	:mX(0), mY(0)
{
}

MVector::MVector(int x, int y)
	:mX(x), mY(y)
{
}

int MVector::GetX() const
{
	return mX;
}

int MVector::GetY() const
{
	return mY;
}

void MVector::SetX(int x)
{
	mX = x;
}

void MVector::SetY(int y)
{
	mY = y;
}

void MVector::Add(const MVector& vector)
{
	mX += vector.mX;
	mY += vector.mY;
}

void MVector::Run()
{
	std::cout << "	----	Ex Vector	----	" << std::endl;

	MVector* vector = new MVector();
	MVector* vector2 = new MVector(100, 200);
	MVector vector3 = MVector(1000, 2000);

	std::cout << "vector 1: x = " << vector->GetX() << " / y = " << vector->GetY() << std::endl;
	std::cout << "vector 2: x = " << vector2->GetX() << " / y = " << vector2->GetY() << std::endl;
	std::cout << "vector 3: x = " << vector3.GetX() << " / y = " << vector3.GetY() << std::endl;

	vector->SetX(10);
	vector->SetY(20);

	vector->Add(*vector2);

	std::cout << "vector 1: x = " << vector->GetX() << " / y = " << vector->GetY() << std::endl;
	std::cout << "vector 2: x = " << vector2->GetX() << " / y = " << vector2->GetY() << std::endl;
	std::cout << "vector 3: x = " << vector3.GetX() << " / y = " << vector3.GetY() << std::endl;

	vector->Add(vector3);
	std::cout << "vector 1: x = " << vector->GetX() << " / y = " << vector->GetY() << std::endl;
	std::cout << "vector 2: x = " << vector2->GetX() << " / y = " << vector2->GetY() << std::endl;
	std::cout << "vector 3: x = " << vector3.GetX() << " / y = " << vector3.GetY() << std::endl;

}
