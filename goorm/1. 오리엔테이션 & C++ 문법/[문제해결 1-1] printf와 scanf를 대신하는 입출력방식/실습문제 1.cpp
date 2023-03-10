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

