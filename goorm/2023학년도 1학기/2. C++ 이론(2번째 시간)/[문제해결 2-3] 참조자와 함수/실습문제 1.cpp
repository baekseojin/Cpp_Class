/*

⋅참조자를 이용해서 다음 요구사항에 부합하는 함수를 정의하고, 이를 호출하는 main 함수도 작성하시오.

-인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수

-인자로 전달된 int형 변수의 부호를 바꾸는 함수

*/

#include <iostream>
using namespace std;

void inc(int &num)
{
    num++;
}

void sign(int & num)
{
    num*=-1;
}

int main(void)
{
	int val=20;
	inc(val);
	cout<<val<<endl;
	sign(val);
	cout<<val;
	return 0;
}