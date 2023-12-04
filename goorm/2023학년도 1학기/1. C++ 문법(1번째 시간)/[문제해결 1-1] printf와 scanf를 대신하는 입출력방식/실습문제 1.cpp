// <문제 1> 사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성하여 제출하시오.

#include <iostream>

int main()
{
    int n=0;
    int result = 0;
    for(int i=0; i<5; i++) {
        std::cin>>n;
        result += n;
    }
    std::cout<<result<<std::endl;
    
    return 0;
}

