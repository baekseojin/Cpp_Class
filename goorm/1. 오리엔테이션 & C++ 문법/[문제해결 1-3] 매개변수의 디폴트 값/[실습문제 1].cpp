#include<iostream>

int BoxVolume(int length, int width=1, int height=1)
{
    return length*width*height;
}

int main()
{
	std::cout<<BoxVolume(3, 3, 3)<<' ';
	std::cout<<BoxVolume(5, 5)<<' ';
	std::cout<<BoxVolume(7);
	return 0;
}

// 실행 결과 : 27 25 7