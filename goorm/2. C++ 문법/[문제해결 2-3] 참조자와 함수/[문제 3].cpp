/*

int main(void)
{
    int num1=5;
    int *ptr1=&num1;
    int num2=10;
    int *ptr2=&num2;
    return 0;
}

*/

/*
위의 코드를 보면 ptr1과 ptr2가 각각 num1과 num2를 가리키고 있다. 
이 때 ptr1과 ptr2를 대상으로 main 함수에서 SwapPointer(ptr1, ptr2); 의 형태로 호출하고 나면 ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 작성하시오.
*/

#include <iostream>
using namespace std;

void SwapPointer(int *(&ptref1), int *(&ptref2)) {
    int *temp = ptref1; 
    ptref1 = ptref2;
    ptref2 = temp;
}

int main(void) {
    int num1 = 5;
    int *ptr1 = &num1; 
    int num2 = 10;
    int *ptr2 = &num2;
    
    SwapPointer(ptr1, ptr2);
    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;
    return 0;
}