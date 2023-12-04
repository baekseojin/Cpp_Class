#include <iostream>
using namespace std;

//swap 함수 부분 작성
void swap(int *a, int *b) {
	int temp = **(&a);
	*a = *b;
	cout<<*a<<*b<<*temp<<endl;
	*b = *temp;
}

void swap(char *a, char *b) {
	char *temp = **(&a);
	*a = *b;
	*b = *temp;
}

void swap(double *a, double *b) {
	double *temp = **(&a);
	*a = *b;
	*b = *temp;
}

int main(void)
{
    int a,b;
    char c,d;
    double e,f;
    cin>>a>>b>>c>>d>>e>>f;
		swap(&a,&b);
		swap(&c,&d);
		swap(&e,&f);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f;
	return 0;
}
