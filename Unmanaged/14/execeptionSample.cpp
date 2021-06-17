#include "execeptionSample.h"
#include <exception>
#include <iostream>

using namespace std;

namespace samples
{
    template <typename T>
    class Vector {
    public:
        Vector(size_t size) : size_(size) {
            data_ = new T[size_];
            for (int i = 0; i < size_; i++) {
                data_[i] = 3;
            }
        }
        const T& at(size_t index) const {
            if (index >= size_) {
                throw out_of_range("vector 의 index 가 범위를 초과하였습니다.");
            }
            return data_[index];
        }
        ~Vector() { delete[] data_; }

    private:
        T* data_;
        size_t size_;
    };


    void execeptionSample(void)
    {
        auto data = 0;

        // throw 사용시에 stack에 생성되었던 객체들을 빠짐없이 소멸 (소멸자만 작성되어 있다면)
        Vector<int> v(10);
        try
        {
            data = v.at(0);
        }
        catch (const std::exception& e)
        {
            cout << " Exeception " << e.what() << endl;
        }

        cout << data << endl;
    }
}