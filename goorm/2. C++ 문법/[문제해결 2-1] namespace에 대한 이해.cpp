#include <iostream>

namespace A
{
	void SimpleFunc(void);
}

namespace A
{
	void PrettyFunc(void);
}

namespace B
{
	void SimpleFunc(void);
}

int main(void)
{
	A::SimpleFunc();
	return 0;
}

void A::PrettyFunc(void)
{
	std::cout<<"30 ";
}

void A::SimpleFunc(void)
{
	std::cout<<"20 ";
	PrettyFunc();
	B::SimpleFunc();
}

void B::SimpleFunc(void)
{
	std::cout<<"10 ";
}

// 정답 : 20 30 10