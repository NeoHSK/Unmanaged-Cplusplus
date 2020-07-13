// 04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Vector.h"

int main()
{
    std::cout << "04\n";

	Vector *v = new Vector();

	v->Run();

#if 0
	Vector v1[3];

	Vector *v2 = new Vector[3]();

	v1[0].Run();
	v2[0].Run();
	v2->Run();
#endif
}
