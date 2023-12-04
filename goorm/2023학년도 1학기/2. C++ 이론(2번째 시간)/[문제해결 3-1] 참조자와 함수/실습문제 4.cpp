/*
const int num =12;

1. 포인터 변수를 선언해서 위 변수를 가리키게 함.

2. 1번의 포인터 변수를 참조하는 참조자를 선언함.

3. 1번과 2번을 이용해서 num에 저장된 값을 출력함.
*/

#include <iostream>
using namespace std;

int main(void)
{
    const int num = 12;

    const int *n1 = &num;
    const int *(&n2) = n1;

    cout << *n1 << endl;
    cout << *n2 << endl;

    return 0;
}