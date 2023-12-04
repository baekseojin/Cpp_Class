// 템플릿 시험에 나옴 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) 
{
    return num1+num2;
}
int main(void)
{
    cout<< Add<int>(15, 20)         <<endl;
    cout<< Add<double>(2.9, 3.7)    <<endl;
    cout<< Add<int>(3.2, 3.2)       <<endl;
    cout<< Add<double>(3.14, 2.75)  <<endl;
    return 0;
}

/*
#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) 
{
    return num1+num2;
}
int main(void)
{
    cout<< Add(15, 20)      <<endl;
    cout<< Add(2.9, 3.7)    <<endl;
    cout<< Add(3.2, 3.2)    <<endl;
    cout<< Add(3.14, 2.75)  <<endl;
    return 0;
}
*/

/* 아래 두 코드의 차이점에 대해 템플릿의 특징과 연관지어 서술하시오.

첫 번째 코드는 템플릿의 자료형을 직접 지정해주었고 
두 번째 코드는 템플릿의 자료형을 직접 지정해주지 않았다.

두 번째 코드는 템플릿의 자료형을 직접 지정해주지 않았기 때문에 매개변수의 자료형에 따라 각각 int, double, double, double로 템플릿이 지정되고
첫 번째 코드는 템플릿의 자료형을 직접 지정해주었기 때문에 int, double, int, double로 템플릿의 자료형이 지정된다.

그런데 첫 번째 코드의 main의 3번째 출력문은 매개변수의 자료형이 double인데도 템플릿을 int로 선언했기 때문에 소숫점이 짤려서 매개변수로 3,3 이렇게 들어가게 된다.

*/