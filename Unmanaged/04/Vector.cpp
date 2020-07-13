#include "Vector.h"

using namespace std;

Vector::Vector()
	:mX(1), mY(1) 
{
	mXY = new int;
	*mXY = mX * mY;
}

Vector::Vector(int x, int y)
	:mX(x), mY(y)
{
	mXY = new int;
	*mXY = x*y;
}

/* 복사 생성자 */
Vector::Vector(const Vector& v)
	:mX(v.mX), mY(v.mY)
{
	mXY = new int;
	*mXY = *v.mXY;
}

/* 이동 생성자 */
Vector::Vector(Vector&& v)
	:mX(v.mX), mY(v.mY), mXY(v.mXY)
{
	v.mXY = nullptr;
	v.mX = 0;
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

bool Vector::operator==(const Vector& rhs) const
{
	if (mX == rhs.mX && mY == rhs.mY && *mXY == *rhs.mXY)
		return true;
	return false;
}

/*대입 연산자*/
Vector& Vector::operator=(const Vector& rhs)
{
	if (this == &rhs)
		return *this;
	
	if(this != nullptr) // nullptr 이라도 delete 해도 됨
		delete mXY;

	mXY = new int;

	mX = rhs.mX;
	mY = rhs.mY;
	*mXY = *rhs.mXY;
	/* 참조 반환 */
	return *this;
}

/*이동 대입연산자*/
Vector& Vector::operator=(Vector&& rhs)
{
	if (this == &rhs)
		return *this;

	delete mXY;

	mX = rhs.mX;
	mY = rhs.mY;
	mXY = rhs.mXY;

	rhs.mXY = 0;
	rhs.mX = 0;
	rhs.mY = 0;
	
	return *this;
}

Vector Vector::operator*(const Vector& rhs) const
{
	Vector vTemp;
	vTemp.mX = mX * rhs.mX;
	vTemp.mY = mY * rhs.mY;
	*vTemp.mXY = *mXY * *rhs.mXY;
	/* 복사 생성자 호출 */
	/* 원래는 복사 생성자 였으나 이동 생상자 호출*/
	return vTemp;
}

Vector Vector::operator*(int multiplier) const
{
	Vector vTemp;
	vTemp.mX = mX * multiplier;
	vTemp.mY = mY * multiplier;
	*vTemp.mXY = *mXY * multiplier;
	/* 복사 생성자 호출*/
	/* 원래는 복사 생성자 였으나 이동 생상자 호출*/
	return vTemp;
}

Vector& Vector::operator*=(const Vector& rhs)
{
#if 1
	mX *= rhs.mX;
	mY *= rhs.mX;
	*mXY *= *rhs.mXY;
	/* 참조 반환 */
	return *this;

#else
	* this = rhs;
	return *this;
#endif
}


Vector& Vector::operator*=(int multiplier) 
{
	mX *= multiplier;
	mY *= multiplier;

	return *this;
}

/*새로운 개채 반환 옵티마이즈 방법이 없나? */
Vector operator*(int multiplier, const Vector& rhs)	
{
	return Vector(rhs.mX*multiplier, rhs.mY*multiplier);
}

std::ostream& operator<<(std::ostream& out, const Vector& rhs)
{
	out << "mX: "<< rhs.mX << ", " << "mY: " <<rhs.mY <<  ", " << "mXY: " << *rhs.mXY << endl;
	
	return out;
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
	Vector v4(3, 3);
	Vector v5;

	v5 = v4;
	*v3 = *v1;

	/* 주소 표시 */
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	/* ostream 연산자 오버로딩 */
	cout << "v1: " << *v1 << endl;
	cout << "v2: " << *v2 << endl;
	cout << "v3: " << *v3 << endl;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;

	/* == 연산자 오버로딩 */
	cout << "v1 == v2 = " << (*v1 == *v2) << endl;

	/* if shallow copy ?*/
	delete v1;
	/*	operator V3 = v1 deep copy	*/
	cout << "v3, mX:  " << v3->GetX() << endl;

	/*v6로 리턴값에 복사 생성자 호출 */
	/*v6로 리턴값 원래는 복사 생성자 였으나 이동 생상자 호출*/
	/* 이동 대입, 이동 대입 연산자가 실행되지 않는 이유는 v6를 처음 생성했기 때문*/
	Vector v6 = v4 * v5;
	cout << "v6: " << v6 << endl;
	   
	v6 = v4 * multiplier;
	/* 같은 의미*/
	v6 =  v4.operator* (multiplier);

	cout << "v6: " << v6 << endl;

	v6 *=*v2;
	cout << "v6: " << v6 << endl;

	v6 *= v6;
	cout << "v6: " << v6 << endl;

	Out(&v6, *v2, *v3);

	cout << "v6: " << v6 << endl;

}

/* 아무 생성자도 호출 되지 않는다 C Style*/
void Vector::Out(Vector* out, Vector& in1, Vector& in2)
{
	out->mX = in1.mX* in2.mX;
}

