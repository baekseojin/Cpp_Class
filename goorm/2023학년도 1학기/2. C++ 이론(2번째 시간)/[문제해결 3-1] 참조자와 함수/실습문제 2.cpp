#include <iostream>
using namespace std;

int &RefRetFuncOne(int &ref)
{
	ref++;
	return ref; // 변수 자체를 반환
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1);

	num1 += 1;
	num2 += 100;
	cout << num1 << ' ' << num2;
	return 0;
}

// 실행 결과 : 3 102