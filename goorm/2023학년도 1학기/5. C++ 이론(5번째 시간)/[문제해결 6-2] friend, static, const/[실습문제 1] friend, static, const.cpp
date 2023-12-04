#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
        cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
    }
};
int SoSimple::simObjCnt=0;

class SoComplex
{
private:
    static int cmxObjCnt;
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
    }
    SoComplex(SoComplex & copy)
    {
        cmxObjCnt++;
        cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
    }
};
int SoComplex::cmxObjCnt=0;

int main(void)
{
    SoSimple sim1; // 객체 생성
    SoSimple sim2; // 객체 생성

    SoComplex cmx1;
    SoComplex cmx2=cmx1;
    SoComplex();
    return 0;
}

/* 출력결과

1번째 SoSimple 객체
2번째 SoSimple 객체
1번째 SoComplex 객체
2번째 SoComplex 객체
3번째 SoComplex 객체

*/