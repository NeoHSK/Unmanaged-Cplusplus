#pragma once
class MVector
{
public:
	MVector();
	MVector(int x, int y);
	~MVector() {};

	int GetX() const;
	void SetX(int x);

	int GetY() const;
	void SetY(int y);

	void Add(const MVector& vector);
	
	bool IsEqual(const MVector& vector) const;
	MVector Multiply(const MVector& vector) const;
	MVector Multiply(const int multiplier)const;

	void Scale(const MVector& vector);
	void Scale(const int muliplier);

	//friend std::ostream operator<<(std::ostream& out, const MVector& mv);
	friend std::ostream& operator<<(std::ostream& out, const MVector& mv);

	void Run();

protected:

private:
	int mX;
	int mY;

};

