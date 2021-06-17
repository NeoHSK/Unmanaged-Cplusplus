#include "stackUnwindingSample.h"


#include <iostream>
#include <stdexcept>

namespace samples
{
    class Resource {
    public:
        Resource(int id) : id_(id) {}
        ~Resource() { std::cout << "리소스 해제 : " << id_ << std::endl; }

    private:
        int id_;
    };

    int func3() {
        Resource r(3);
        throw std::runtime_error("Exception from 3!\n");
    }
    int func2() {
        Resource r(2);
        func3();
        std::cout << "실행 안됨!" << std::endl;
        return 0;
    }
    int func1() {
        Resource r(1);
        func2();
        std::cout << "실행 안됨!" << std::endl;
        return 0;
    }

    /*
    가장 가까운 catch 에서 예외를 받음.
    func1, 2 모두 예외를 받는 catch 구문이 없음.
    가장 가까운 main 함수에 있는 catch 구문이 실행,

    예외가 전파되면서 각 함수들에 정의되어 있던 객체들이 잘 소멸.
    
    예외를 생성자에서 던질 때 주의
    예외가 발생 시에 소멸자가 호출되지 않음.
    만일 예외를 던지기 이전에 획득한 자원이 있다면 catch 에서 잘 해제.
    */
    void stackUnwindingSample(void)
    {
        try
        {
            func1();
        }
        catch (std::exception& e)
        {
            std::cout << "Exception : " << e.what();
        }
    }
}