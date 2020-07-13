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

/* ���� ������ */
Vector::Vector(const Vector& v)
	:mX(v.mX), mY(v.mY)
{
	mXY = new int;
	*mXY = *v.mXY;
}

/* �̵� ������ */
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

/*���� ������*/
Vector& Vector::operator=(const Vector& rhs)
{
	if (this == &rhs)
		return *this;
	
	if(this != nullptr) // nullptr �̶� delete �ص� ��
		delete mXY;

	mXY = new int;

	mX = rhs.mX;
	mY = rhs.mY;
	*mXY = *rhs.mXY;
	/* ���� ��ȯ */
	return *this;
}

/*�̵� ���Կ�����*/
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
	/* ���� ������ ȣ�� */
	/* ������ ���� ������ ������ �̵� ������ ȣ��*/
	return vTemp;
}

Vector Vector::operator*(int multiplier) const
{
	Vector vTemp;
	vTemp.mX = mX * multiplier;
	vTemp.mY = mY * multiplier;
	*vTemp.mXY = *mXY * multiplier;
	/* ���� ������ ȣ��*/
	/* ������ ���� ������ ������ �̵� ������ ȣ��*/
	return vTemp;
}

Vector& Vector::operator*=(const Vector& rhs)
{
#if 1
	mX *= rhs.mX;
	mY *= rhs.mX;
	*mXY *= *rhs.mXY;
	/* ���� ��ȯ */
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

/*���ο� ��ä ��ȯ ��Ƽ������ ����� ����? */
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

	/* �ּ� ǥ�� */
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	/* ostream ������ �����ε� */
	cout << "v1: " << *v1 << endl;
	cout << "v2: " << *v2 << endl;
	cout << "v3: " << *v3 << endl;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;

	/* == ������ �����ε� */
	cout << "v1 == v2 = " << (*v1 == *v2) << endl;

	/* if shallow copy ?*/
	delete v1;
	/*	operator V3 = v1 deep copy	*/
	cout << "v3, mX:  " << v3->GetX() << endl;

	/*v6�� ���ϰ��� ���� ������ ȣ�� */
	/*v6�� ���ϰ� ������ ���� ������ ������ �̵� ������ ȣ��*/
	/* �̵� ����, �̵� ���� �����ڰ� ������� �ʴ� ������ v6�� ó�� �����߱� ����*/
	Vector v6 = v4 * v5;
	cout << "v6: " << v6 << endl;
	   
	v6 = v4 * multiplier;
	/* ���� �ǹ�*/
	v6 =  v4.operator* (multiplier);

	cout << "v6: " << v6 << endl;

	v6 *=*v2;
	cout << "v6: " << v6 << endl;

	v6 *= v6;
	cout << "v6: " << v6 << endl;

	Out(&v6, *v2, *v3);

	cout << "v6: " << v6 << endl;

}

/* �ƹ� �����ڵ� ȣ�� ���� �ʴ´� C Style*/
void Vector::Out(Vector* out, Vector& in1, Vector& in2)
{
	out->mX = in1.mX* in2.mX;
}

