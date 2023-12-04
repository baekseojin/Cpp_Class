#include <iostream>
using namespace std;
class AAA
{
public:
    void ShowYou() { cout<<"AAA"<<endl; }
};
class BBB : public AAA
{
public:
    void ShowYou() { cout<<"BBB"<<endl; }
};
class CCC : public BBB
{
public:
    void ShowYou() { cout<<"CCC"<<endl; }
};
void ExceptionGenerator(int expn)
{
    if(expn==1)
        throw AAA();
    else if(expn==2)
        throw BBB();
    else
        throw CCC();
}
int main(void)
{
    int expn;
    cin>>expn;
   
	  //예외처리 구문 작성
		try {
			ExceptionGenerator(expn);
			
		} catch(CCC a) {
			cout<<"catch CCC"<<endl;
			a.ShowYou();
		} 
		catch(BBB a) {
			cout<<"catch BBB"<<endl;
			a.ShowYou();
		}
		catch(AAA a) {
			cout<<"catch AAA"<<endl;
			a.ShowYou();
		}
		
		
    return 0;
}
