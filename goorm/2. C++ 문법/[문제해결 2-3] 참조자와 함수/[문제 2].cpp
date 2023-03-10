// 위 예제 코드 main 함수에서 SwapByRef2(23,45); 의 형태로 호출하면 컴파일 에러가 발생하는 이유에 대해 서술하시오.

#include <iostream>
using namespace std;

void SwapByRef1(int *ref1, int *ref2)
{
	int temp=*ref1;
	*ref1=*ref2;
	*ref2=temp;
}

void SwapByVal(int ref1, int ref2)
{
	int temp=ref1;
	ref1=ref2;
	ref2=temp;
}

void SwapByRef2(int &ref1, int& ref2)
{
	int temp=ref1;
	ref1=ref2;
	ref2=temp;
}

int main(void)
{
	int val1=10;
	int val2=20;

	SwapByVal(val1,val2);
	cout<<val1<<' '<<val2<<endl;

    SwapByRef1(&val1, &val2);
    cout<<val1<<' '<<val2<<endl;

	SwapByRef2(val1, val2);
	cout<<val1<<' '<<val2<<endl;
	// SwapByRef2(23, 45)의 형태로 호출하면 int &ref1 = 23,
	// int &ref2 = 45가 되는데, 앰퍼샌드와 선언이 되면 
	// 주소값이 있는 것이 대입되어야 하기 때문에 변수가 매개변수로
	// 들어오면 안된다
	return 0;
}