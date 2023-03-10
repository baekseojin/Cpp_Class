#include <iostream>
using namespace std;

int main(void) {
    const int num = 12;
    
    const int *n1 = &num;
    const int *(&n2) = n1;
    
    cout<<*n1<<endl;
    cout<<*n2<<endl;
    
    return 0;
}