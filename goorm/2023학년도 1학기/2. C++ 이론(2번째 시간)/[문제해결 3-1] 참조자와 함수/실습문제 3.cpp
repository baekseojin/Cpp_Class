#include <iostream>
using namespace std;

int RefRetFuncTwo(int &ref)
{
    ref++;
    return ref; // 상수(값)을 반환
}

int main(void)
{
    int num1 = 1;
    int num2 = RefRetFuncTwo(num1);

    num1 += 1;
    num2 += 100;
    cout << num1 << ' ' << num2;
    return 0;
}

// 실행 결과 : 3 102