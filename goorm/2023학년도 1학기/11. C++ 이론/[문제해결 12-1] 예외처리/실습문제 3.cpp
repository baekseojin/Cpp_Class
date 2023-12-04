#include <iostream>
#include <cstring>
using namespace std;

class AccountException
{
public:
    virtual void ShowExceptionReason() =0;
};

class DepositException : public AccountException
{
private:
    int reqDep;     // 요청 입금액
public:
    DepositException(int money) : reqDep(money)
    { }
    void ShowExceptionReason()
    {
        cout<<"[예외 메시지: "<<reqDep<<"는 입금불가]"<<endl;
    }
};

class WithdrawException : public AccountException
{
private:
    int balance;    // 잔고
public:
    WithdrawException(int money) : balance(money)
    { }
    void ShowExceptionReason()
    {
        cout<<"[예외 메시지: 잔액 "<<balance<<", 잔액부족]"<<endl;
    }
};

class Account
{
private:
    char accNum[50];    // 계좌번호
    int balance;        // 잔고
public:
    Account(char * acc, int money) : balance(money)
    {
        strcpy(accNum, acc);
    }
    void Deposit(int money) throw (AccountException) // throw로 던지는 객체의 자료형(클래스)를 AccountException으로 제한
    {
        if(money<0)
        {
            DepositException expn(money);
            throw expn; // DepositException은 AccountException을 상속받고 있으니까(더 큰 개념이니까) 제한된 자료형(클래스)이 AccountException이여도 throw가 가능하다.
        }
        balance+=money;
    }
    void Withdraw(int money) throw (AccountException)
    {
        if(money>balance)
            throw WithdrawException(balance);
        balance-=money;
    }
    void ShowMyMoney()
    {
        cout<<"잔고: "<<balance<<endl<<endl;
    }
};

int main(void)
{
    Account myAcc("56789-827120", 5000);

    try
    {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    catch(AccountException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    }
    catch(AccountException &expn)
    {
        expn.ShowExceptionReason();
    }   
    myAcc.ShowMyMoney();
    return 0;
}



/*
AccountException이라는 예외 검출 클래스의 최상위 클래스를 만들고, ShowExceptionReason()을 자식 클래스가 오버라이딩 할 수 있도록 가상 함수로 정의했다. 가상함수로 정의해야 객체가 가르키고 있는 곳으로 가기 때문에 throw했을 때 최상위 클래스인 AccountException으로 가지 않고 자기가 가르키는 클래스로 가기 때문에 virtual을 사용한다.
throw를 각각의 예외 검출 클래스형으로 제한했었는데, 이들의 부모 클래스인 AccountException으로 제한했다.
*/