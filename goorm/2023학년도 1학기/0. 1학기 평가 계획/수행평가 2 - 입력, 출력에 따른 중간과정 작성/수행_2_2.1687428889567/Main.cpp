#include <iostream>

using namespace std;

// 함수 작성
int& RefRetFuncOne(int &n1) {
	return n1 += 1;
}


int main(void)
{
	int num1;
	cin>>num1; // 100
	int &num2=RefRetFuncOne(num1);
	num1++;
	num2++;
	cout<<num1<<' '<<num2;
	return 0;
}