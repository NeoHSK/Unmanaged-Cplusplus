#pragma once
#include <iostream>

class Vector
{
public:
	/*생성자*/
	Vector();
	Vector(int x, int y);
	/* 복사 생성자 */
	Vector(const Vector& v);
	/* 이동 생성자 */
	Vector(Vector&& v);

	~Vector();

	int GetX() const;
	void SetX(int x); 

	int GetY() const;
	void SetY(int y);

	void Run();

	void Out(Vector* out, Vector& in1, Vector& in2);


	bool operator==(const Vector& rhs) const;

	Vector& operator=(const Vector& rhs);

	/* 이동 대입연산자 */
	Vector& operator=(Vector&& rhs);

	/* 새로운 개체 반환, 반환형이 달라 아래 함수와는 다른 것  */
	Vector operator*(const Vector& rhs) const ;
	Vector operator*(int multiplier) const;

	/* 나 자신을 반환, 반환형이 달라 위 함수와 다름 */
	Vector& operator*=(const Vector& rhs);
	Vector& operator*=(int multiplier);


	friend Vector operator*(int multiplier, const Vector& rhs);
	
	friend std::ostream& operator<<(std::ostream& out, const Vector& rhs);

protected:

private:

	int mX;
	int mY;
	int* mXY;

};

