// 02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "ExString.h"
#include "ExFile.h"
#include "MVector.h"

int main()
{
    std::cout << "02!\n";
#if 0 
    ExString *ex = new ExString();
    //ex->Mirror();
    //ex->Stream();
#elif 0 
    ExFile* ex = new ExFile();
    ex->run();
    return 0;
#else
    MVector* vector = new MVector();
    vector->Run();
#endif
}
