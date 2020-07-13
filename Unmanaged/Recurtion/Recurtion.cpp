// Recurtion.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void tail(int n)
{
	if (n == 0)
		return;
	
	cout << "Print: "<< n << endl;
	
	tail(n - 1);
}

void head(int n)
{
	if (n == 0)
		return;

	head(n - 1);

	cout << "Print: "<< n << endl;
}

/* tail recurtion */
int sum(int n)
{
	if (n == 1)
		return 1;

	return n + sum(n - 1);
}

int main()
{
	int temp = 0;

    std::cout << " Recurtion !\n";

	//temp = sum(5);
	tail(5);
	std::cout<< temp << " End !\n";

}

