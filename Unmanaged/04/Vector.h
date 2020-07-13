#pragma once
#include <iostream>

class Vector
{
public:
	/*������*/
	Vector();
	Vector(int x, int y);
	/* ���� ������ */
	Vector(const Vector& v);
	/* �̵� ������ */
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

	/* �̵� ���Կ����� */
	Vector& operator=(Vector&& rhs);

	/* ���ο� ��ü ��ȯ, ��ȯ���� �޶� �Ʒ� �Լ��ʹ� �ٸ� ��  */
	Vector operator*(const Vector& rhs) const ;
	Vector operator*(int multiplier) const;

	/* �� �ڽ��� ��ȯ, ��ȯ���� �޶� �� �Լ��� �ٸ� */
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

