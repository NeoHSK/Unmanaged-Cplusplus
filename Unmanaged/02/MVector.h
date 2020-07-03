#pragma once
class MVector
{
public:
	MVector();
	MVector(int x, int y);
	~MVector() {};

	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);

	void Add(const MVector& vector);
	void Run();

protected:

private:
	int mX;
	int mY;

};

