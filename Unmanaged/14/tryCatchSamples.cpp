#include "tryCatchSamples.h"

namespace samples
{

    int func(int c)
    {
        if (c == 1)
        {
            throw 10;
        }
        else if (c == 2)
        {
            throw std::string("hi!");
        }
        else if (c == 3)
        {
            throw 'a';
        }
        else if (c == 4)
        {
            throw "hello!";
        }
        else if (c == 5)
        {
            throw std::runtime_error(" Runtime error ");
        }
        else
        {
            throw 10.1f;
        }
        return 0;
    }


    void tryCatchSample(void)
    {
        int c;
        std::cin >> c;

        try
        {
            func(c);
        }
        catch (char x)
        {
            std::cout << "Char : " << x << std::endl;
        }
        catch (int x)
        {
            std::cout << "Int : " << x << std::endl;
        }
        catch (std::string& s)
        {
            std::cout << "String : " << s << std::endl;
        }
        catch (const char* s)
        {
            std::cout << "String Literal : " << s << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Eceception  : " << e.what() << std::endl;
        }
        catch (...) // ��� ���� �� ����
        {
            std::cout << "Eceception default : " << std::endl;
        }
    }

    int foo() noexcept{ return 1; }

    int bar()  noexcept { throw "noexecept";  return 2; }

    void noExeceptSample(void)
    {
        foo();
        
        try
        {
            bar();
        }
        catch(const std::exception& e)
        {
            //noexcept�� ��õ� �Լ��� throw�� �� ��� ���� �߻�  
        }
    }

    //C++ 11 ���� ���� �Ҹ��ڵ��� �⺻������ noexcept, �Ҹ��ڿ��� ���ܸ� ������ �ȵ˴ϴ�.


    class Parent : public std::exception {
    public:

        // what �� std::exception �� ���ǵ� �Լ���, �� ���ܰ� �������� �����ϴ� ���ڿ���
        // �����ϴ� �Լ� �Դϴ�.
        virtual const char* what() const noexcept override { return "Parent!\n"; }
    };

    class Child : public Parent {
    public:
        const char* what() const noexcept override { return "Child!\n"; }
    };

    int func(int c) {
        if (c == 1) {
            throw Parent();
        }
        else if (c == 2) {
            throw Child();
        }
        return 0;
    }

    void inheritExeception()
    {
        int c;
        std::cin >> c;

        try 
        {
            func(c);
        }
        // �θ��� throw�� ���� ó���ϱ� ������ Child�� ���� �޴´�.
        catch (Child& c)
        {
            std::cout << "Child Catch!" << std::endl;
            std::cout << c.what();
        }
        catch (Parent& p) {
            std::cout << "Parent Catch!" << std::endl;
            std::cout << p.what();
        }
    }


}