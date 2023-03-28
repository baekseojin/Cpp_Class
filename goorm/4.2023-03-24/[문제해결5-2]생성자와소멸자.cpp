/*
#include <iostream>
using namespace std;

class SimpleClass
{
	int num1;
	int num2;

public:
	SimpleClass()
	{
		num1=0;
		num2=0;
	}
	SimpleClass(int n)
	{
		num1=n;
		num2=0;
	}
	SimpleClass(int n1, int n2)
	{
		num1=n1;
		num2=n2;
	}
	SimpleClass(int n1=0, int n2=0)
	{
		num1=n1;
		num2=n2;
	}
	void ShowData() const
	{
		cout<<num1<<' '<<num2<<endl;
	}
};

int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

class SimpleClass
{
	int num1;
	int num2;

public:
	SimpleClass()
	{
		num1=0;
		num2=0;
	}
	SimpleClass(int n)
	{
		num1=n;
		num2=0;
	}
	SimpleClass(int n1, int n2)
	{
		num1=n1;
		num2=n2;
	}
};
int main(void)
{
    SimpleClass sc1;
    SimpleClass sc1(); // 정적할당은 ()이 붙어있는 것을 생성자를 호출한다고 생각하지 않고 ()를 함수로 인식해서 컴파일러가 안됨
    SimpleClass * ptr1=new SimpleClass;
    SimpleClass * ptr1=new SimpleClass(); // 동적할당은 ()이 붙어있거나 안붙어있어도 다 생성자로 인식한다 
	return 0;
}
*/