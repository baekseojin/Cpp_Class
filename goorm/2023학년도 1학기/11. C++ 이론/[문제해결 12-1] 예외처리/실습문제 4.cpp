#include <iostream>
using namespace std;

class AAA
{
public:
    void ShowYou() { cout<<"AAA exception!"<<endl; }
};

class BBB : public AAA
{
public:
    void ShowYou() { cout<<"BBB exception!"<<endl; }
};

class CCC : public BBB
{
public:
    void ShowYou() { cout<<"CCC exception!"<<endl; }
};

void ExceptionGenerator(int expn)
{
    if(expn==1)
        throw AAA();
    else if(expn==2)
        throw BBB();
    else
        throw CCC();
}

int main(void)
{
    try
    {
        ExceptionGenerator(3);
        ExceptionGenerator(2);
        ExceptionGenerator(1);
    }
    catch(AAA& expn)
    {
        cout<<"catch(AAA& expn)"<<endl;
        expn.ShowYou();
    }
    catch(BBB& expn)
    {
        cout<<"catch(BBB& expn)"<<endl;
        expn.ShowYou();
    }
    catch(CCC& expn)
    {
        cout<<"catch(CCC& expn)"<<endl;
        expn.ShowYou();
    }
    return 0;
}

/*
CCC A = CCC B; 자기 자신의 클래스기 때문에 대입 가능

BBB A = BBB B; 자기 자신의 클래스기 때문에 대입 가능
BBB A = CCC B; CCC가 BBB를 상속받았기 때문에 가능

AAA A = AAA B; 자기 자신의 클래스기 때문에 대입 가능
AAA A = BBB B; BBB가 AAA를 상속받았기 때문에 가능
AAA A = CCC B; CCC가 AAA를 상속받았기 때문에 가능

결론 : 자기 자신과 상속받은 클래스는 가능
*/


/*
CCC는 BBB를, BBB는 AAA를 상속받고 있다. throw로 CCC의 임시 객체를 보내면 catch문은 위에서부터 차례대로 실행하므로, CCC는 부모 클래스인 AAA 클래스에 해당이 되어 첫 번째 catch문을 실행한다. 또한 try문은 한번 예외가 발견되면 나머지 구문은 실행하지 않으므로, 한번만 출력된다.
*/