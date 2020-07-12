#include "Vector.h"

using namespace std;

Vector::Vector()
	:mX(1), mY(1)
{
	mXY = new int;
	*mXY = mX * mY;
}

Vector::Vector(int x, int y)
{
	mX = x;
	mY = y;
	mXY = new int;
	*mXY = x*y;
}

Vector::Vector(const Vector& v)
{
	mX = v.mX;
	mY = v.mY;
	mXY = new int;
	*mXY = *v.mXY;

}

Vector::~Vector()
{
	delete mXY;
}

int Vector::GetX() const
{
	return mX;
}

void Vector::SetX(int x)
{
	mX = x;
}

int Vector::GetY() const
{
	return mY;
}

void Vector::SetY(int y)
{
	mY = y;
}

void Vector::Run()
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Operator Overloading Example " << std::endl;
	std::cout << "-----------------------------" << std::endl;

	constexpr int multiplier = 3;

	/* heap */
	Vector* v1 = new Vector();
	Vector* v2 = new Vector(*v1);
	Vector* v3 = new Vector();

	/* stack */
	Vector v4(3,3);
	Vector v5;

	v5 = v4;
	*v3 = *v1;

	/* 주소 표시 */
	cout <<	"v1: "<< v1	<<endl;
	cout << "v2: "<< v2 <<endl;

	/* ostream 연산자 오버로딩 */
	cout << "v1: " << *v1 << endl;
	cout << "v2: " << *v2 << endl;
	cout << "v3: " << *v3 << endl;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;

	/* == 연산자 오버로딩 */
	cout << "v1 == v2 = " << (*v1== *v2) << endl;

	/* if shallow copy ?*/
	delete v1;
	/*	operator V3 = v1 deep copy	*/
	cout << "v3, mX:  " << v3->GetX() << endl;
}

bool Vector::operator==(const Vector& rhs) const
{
	if (mX == rhs.mX && mY == rhs.mY && *mXY == *rhs.mXY)
		return true;
	return false;
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (this == &rhs)
		return *this;
	
	if(this != nullptr)
		delete mXY;

	mXY = new int;

	mX = rhs.mX;
	mY = rhs.mY;
	*mXY = *rhs.mXY;

	return *this;
}

Vector& Vector::operator*(const Vector& rhs)
{
	*this = rhs;
	return *this;
}

Vector& Vector::operator*(int multiplier) 
{
	mX *= multiplier;
	mY *= multiplier;

	return *this;
}

/*새로운 개채 반환*/
Vector operator*(int multiplier, const Vector& rhs)	
{
	return Vector(rhs.mX*multiplier, rhs.mY*multiplier);
}

std::ostream& operator<<(std::ostream& out, const Vector& rhs)
{
	out << "mX: "<< rhs.mX << "," << "mY: " <<rhs.mY << endl;
	
	return out;
}
