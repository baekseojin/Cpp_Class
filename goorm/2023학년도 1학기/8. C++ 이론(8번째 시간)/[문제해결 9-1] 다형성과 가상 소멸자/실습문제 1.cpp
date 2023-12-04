#include <iostream>
using namespace std;

class First
{
public:
    void func()
    {
        cout<<"func"<<endl;
    }
    virtual void MyFunc()
    {
        cout<<"FirstFunc"<<endl;
    }
};

class Second: public First
{
public:
    void sfunc()
    {
        cout<<"sfunc"<<endl;
    }
    virtual void MyFunc()
    {
        cout<<"SecondFunc"<<endl;
    }
};

class Third: public Second
{
public:
    void tfunc()
    {
        cout<<"tfunc"<<endl;
    }
    virtual void MyFunc()
    {
        cout<<"ThirdFunc"<<endl;
    }
};

int main(void)
{
    Third * tptr=new Third();
    Second * sptr=tptr;
    First * fptr=sptr;

    fptr->MyFunc();
    fptr->func();
    sptr->MyFunc();
    sptr->sfunc();
    tptr->MyFunc();
    tptr->tfunc();
    delete tptr;
    return 0;
}

/* 실행결과

ThirdFunc
func
ThirdFunc
sfunc
ThirdFunc
tfunc
*/