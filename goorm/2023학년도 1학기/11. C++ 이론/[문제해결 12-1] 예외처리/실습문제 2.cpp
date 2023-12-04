// 여기서 시험문제 나옴 !!!!

#include <iostream>
#include <cstring>
using namespace std;

class DepositException
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

class WithdrawException
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
    void Deposit(int money) throw (DepositException) // throw(DepositException) : DepositException 자료형의 객체 or 변수만 던지겠다.
    {
        if(money<0)
        {
            DepositException expn(money);
            throw expn; 
        }
        balance+=money;
    }
    void Withdraw(int money) throw (WithdrawException)
    {
        if(money>balance)
            throw WithdrawException(balance); // 임시 객체를 생성함.
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
        myAcc.Deposit(2000); // 입금
        myAcc.Deposit(-300);
    }
    catch(DepositException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.Withdraw(3500); // 출금
        myAcc.Withdraw(4500);
    }
    catch(WithdrawException &expn)
    {
        expn.ShowExceptionReason();
    }   
    myAcc.ShowMyMoney();
    return 0;
}

/*
예외를 검출할 클래스를 각각 만든다. 
Account라는 클래스의 함수의 매개변수로 받은 값들을 조건문을 통해 논리에 맞는지 검사하고, 맞지 않다면 예외를 검출하는 클래스 객체를 만들어 해당 객체의 함수를 통해 throw를 보낸다. 
*/