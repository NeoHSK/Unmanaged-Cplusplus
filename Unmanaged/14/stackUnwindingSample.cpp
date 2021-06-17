#include "stackUnwindingSample.h"


#include <iostream>
#include <stdexcept>

namespace samples
{
    class Resource {
    public:
        Resource(int id) : id_(id) {}
        ~Resource() { std::cout << "���ҽ� ���� : " << id_ << std::endl; }

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
        std::cout << "���� �ȵ�!" << std::endl;
        return 0;
    }
    int func1() {
        Resource r(1);
        func2();
        std::cout << "���� �ȵ�!" << std::endl;
        return 0;
    }

    /*
    ���� ����� catch ���� ���ܸ� ����.
    func1, 2 ��� ���ܸ� �޴� catch ������ ����.
    ���� ����� main �Լ��� �ִ� catch ������ ����,

    ���ܰ� ���ĵǸ鼭 �� �Լ��鿡 ���ǵǾ� �ִ� ��ü���� �� �Ҹ�.
    
    ���ܸ� �����ڿ��� ���� �� ����
    ���ܰ� �߻� �ÿ� �Ҹ��ڰ� ȣ����� ����.
    ���� ���ܸ� ������ ������ ȹ���� �ڿ��� �ִٸ� catch ���� �� ����.
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