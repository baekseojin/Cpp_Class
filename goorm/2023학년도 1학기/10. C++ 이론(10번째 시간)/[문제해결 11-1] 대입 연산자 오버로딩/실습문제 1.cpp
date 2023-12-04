// https://vansoft1215.tistory.com/38

#include <iostream>
using namespace std;

class AAA
{
private:
    int num;
public:
    AAA(int n=0): num(n)
    {  
        cout<<"AAA(int n=0)"<<endl;
    }
    AAA(const AAA &ref): num(ref.num)
    {  
        cout<<"AAA(const AAA & ref)"<<endl;
    }
    AAA & operator=(const AAA &ref)
    {
        num=ref.num;
        cout<<"operator=(const AAA &ref)"<<endl;
        return *this;
    }
};

class BBB
{
private:
    AAA mem;
public:
    BBB(const AAA & ref)
        : mem(ref)
    {  }
};

class CCC
{
private:
    AAA mem;
public:
    CCC(const AAA & ref)
    {
        mem=ref;
    }
};

int main(void)
{
    AAA obj1(12);
    cout<<"*********************"<<endl;
    BBB obj2(obj1);
    cout<<"*********************"<<endl;
    CCC obj3(obj1);
    return 0;
}

/*
실행 결과

AAA(int n=0)
**********************
AAA(const AAA & ref)  
**********************
AAA(int n=0)
operator=(const AAA &ref)

복사생성자를 쓰면 변수가 선언된 뒤에 대입을 해주지만 
이니셜라이저를 쓰면 선언과 동시에 객체를 초기화하는 것이기 때문에 편리하다.

*/