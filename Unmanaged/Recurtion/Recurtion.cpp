// Recurtion.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/* tail recurtion 은 stack에 기억해야할, 저장되어야할 (변수)값이 없어야 한다.*/
void tail(int n)
{
	if (n == 0)
		return;
	
	/* print 는 먼저함 저장 되어야할 파라메터가 없다.*/
	cout << "Print: "<< n << endl;
	
	tail(n - 1);
}

void head(int n)
{
	if (n == 0)
		return;

	head(n - 1);

	/* print가 나중에 되므로 저장되어야할 파라메터가 있다.*/
	cout << "Print: "<< n << endl;
}


int sum(int n)
{
	if (n == 1)
		return 1;

	return n + sum(n - 1);
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

long factorial(int n, long result)
{
	if (n == 1)
		return result;

	return factorial(n - 1, n*result);

}

int fibonachi(int n)
{
	/*Base case */
	if (n <= 1)
		return n;

#if 0
	int fb1, fb2;

	fb1 = fibonachi(n - 1);
	fb2 = fibonachi(n - 2);

	return fb1 + fb2;// +fibonachi(n - 2);
#else
	return fibonachi(n - 1) + fibonachi(n - 2);

#endif
}


int fibonachi(int n)
{
	/*Base case */
	if (n <= 1)
		return n;

#if 0
	int fb1, fb2;

	fb1 = fibonachi(n - 1);
	fb2 = fibonachi(n - 2);

	return fb1 + fb2;// +fibonachi(n - 2);
#else
	return fibonachi(n - 1) + fibonachi(n - 2);

#endif
}


int fibonachi(int n)
{


}

int main()
{
	long temp = 1;

    std::cout << " Recurtion !\n";

	//temp = sum(5);
	//tail(5);
	//temp = factorial(10,temp);
	temp = fibonachi(5);
	std::cout << temp << endl;
	std::cout << " End !\n" << endl;;

}

