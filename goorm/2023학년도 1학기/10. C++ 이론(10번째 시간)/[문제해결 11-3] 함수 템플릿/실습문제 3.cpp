#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len)
{
    T sum= (T)0;
    for(int i=0; i<len; i++)
        sum += (arr[i]);
    return sum;
}

int main(void)
{
  char arr1[5] = {'A', 'B', 'C', 'D', 'E'};
  int arr2[5] = {1, 2, 3, 4, 5};
    double arr3[5] = {0.7, 0.5, 1.9, 0.4, 9.7};

    cout << SumArray(arr1, 5) << endl;
    cout << SumArray(arr2, 5) << endl;
    cout << SumArray(arr3, 5) << endl;
    return 0;
}