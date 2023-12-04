# [문제해결 1-1] printf와 scanf를 대신하는 입출력 방식

#### 1. printf를 대신하는 출력
  
```c++
#include <iostream>

int main()
{
    std::cout<<"Hello world!"<<std::endl;
    return 0;
}
```
=> C++의 출력은 `printf` 대신 `cout<<`을 사용한다!


#### 2. scanf를 대신하는 입력

```c++
#include <iostream>

int main()
{
    int val;
    char str[100];
    std::cin>>val>>str;
    std::cout<<val<<' '<<str;
    return 0;
}
```

=> C++의 입력은 `scanf` 대신 `cin>>`을 사용한다!

#### <실습문제 1> 사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성하여 제출하시오.

```c++
#include<iostream>

int main()
{
    int sum=0,a;
    for(int i=1; i<=5; i++)
    {
        std::cin>>a;
        sum+=a;
    }
	std::cout<<sum;
	return 0;
}
```

#### <실습문제 2> 사용자로부터 이름과 전화번호를 문자열 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성하여 제출하시오.

```c++
#include<iostream>

int main()
{
    char name[50], number[50];
    std::cin>>name>>number;
	std::cout<<name<<' '<<number;
	return 0;
}
```

#### <실습문제 3> 숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성하여 제출하시오.( 예를 들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야 한다.)


```c++
#include<iostream>

int main()
{
    int a;
    std::cin>>a;
    for(int i=1; i<=9; i++)
    {
        std::cout<<a<<"x"<<i<<"="<<a*i<<std::endl;
    }
	return 0;
}
```