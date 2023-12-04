// <문제 2> 사용자로부터 이름과 전화번호를 문자열 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성하여 제출하시오.

#include <iostream>

int main()
{   
    char name[10];
    char phnum[20];
    std::cin>>name;
    std::cin>>phnum;
    std::cout<<name<<std::endl;
    std::cout<<phnum;

    return 0;
}
