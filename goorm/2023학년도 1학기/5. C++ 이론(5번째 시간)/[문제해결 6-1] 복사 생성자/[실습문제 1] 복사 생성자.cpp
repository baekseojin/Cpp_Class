#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout<<this<<endl;
    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout<<this<<endl;
    }
    ~SoSimple()
    {
        cout<<this<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout<<&ob<<endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout<<endl;
    SoSimple tempRef=SimpleFuncObj(obj);
    cout<<&tempRef<<endl;
    return 0;
}

/*


*/

/* 실습문제 정답 
출력 결과

1. 100 // obj 객체 생성                             (SoSimple 생성자에서 obj 주소 출력) 
2. 200 // ob 객체 생성                              (SoSimple 복사 생성자에서 ob 주소 출력)
3. 200 // ob 객체 주소 출력                         (SimpleFuncObj 함수에서 ob 주소 출력)
4. 300 // ob가 사라지기 전에 임시객체 1 생성         (복사 생성자에서 주소 출력)
5. 200 // ob 삭제                                  (소멸자에서 주소 출력)
6. 300 // 임시객체 1 삭제                           (소멸자에서 주소 출력)

7. 200 // ob 생성                               (생성자에서 주소 출력)
8. 200 // ob 주소 출력                          
9. 400 // 임시객체2 생성
10. 200 // ob 소멸
11. 400 // 임시객체2 주소 출력
12. 100 // obj 객체 소멸(---- main 함수 끝나서 소멸 ----)
13. 400 // 임시 객체 소멸(---- main 함수 끝나서 소멸 ----)
*/