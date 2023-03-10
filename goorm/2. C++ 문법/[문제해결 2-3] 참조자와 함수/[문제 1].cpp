/*
    참조자를 이용해서 다음 요구사항에 부합하는 함수를 정의하고, 이를 호출하는 main 함수도 작성하시오.

-인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수

-인자로 전달된 int형 변수의 부호를 바꾸는 함수
*/

#include <iostream>
using namespace std;

void Plus(int &num) {
    num += 1;
}

void Sign(int &num) {
    if(num >= 0) {
        num -= (num*2);
    }
    
    else {
        num += num*2;
    }
    
}

int main(void)
{
	int val1=10;
	int val2=20;
    
    Plus(val1);
	Sign(val2);
	cout<<val1<<endl;
    cout<<val2<<endl;

	return 0;
}