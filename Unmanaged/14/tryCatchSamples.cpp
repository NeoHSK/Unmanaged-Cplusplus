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
        catch (...) // 모든 것을 다 받음
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
            //noexcept로 명시된 함수가 throw를 할 경우 에러 발생  
        }
    }

    //C++ 11 에서 부터 소멸자들은 기본적으로 noexcept, 소멸자에서 예외를 던지면 안됩니다.


    class Parent : public std::exception {
    public:

        // what 은 std::exception 에 정의된 함수로, 이 예외가 무엇인지 설명하는 문자열을
        // 리턴하는 함수 입니다.
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
        // 부모의 throw를 먼저 처리하기 때문에 Child를 먼저 받는다.
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