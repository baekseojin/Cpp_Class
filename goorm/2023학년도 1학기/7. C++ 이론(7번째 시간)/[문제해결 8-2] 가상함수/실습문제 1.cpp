#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
private:
   string name;
public:
   Employee(string name)
   {
      this->name=name;
   }
   void ShowYourName() const
   {
      cout<<"name: "<<name<<endl;
   }
   
   // GetPay와 ShowSalaryInfo를 부모에 생성하고 virtual을 작성해서 객체 기준으로 접근하게끔 한다(virtual을 안붙이면 부모의 GetPay와 ShowSalaryInfo에만 접근하니까)
   virtual int GetPay() const = 0;
   virtual void ShowSalaryInfo() const = 0;
};
class PermanentWorker : public Employee
{
private:
   int salary;
public:
   PermanentWorker(string name, int money)
      : Employee(name), salary(money)
   {  }
   int GetPay() const
   {
      return salary;
   }
   void ShowSalaryInfo() const
   {
      ShowYourName();
      cout<<"salary: "<<GetPay()<<endl<<endl;
   }
};
class TemporaryWorker : public Employee
{
private:
    int workTime; //일한 시간
    int payPerHour; //시급
public :
    TemporaryWorker(string name, int pay) : Employee(name),workTime(0),payPerHour(pay)
    {}
    void AddWorkTime(int time)
    {
        workTime+=time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
   {
      ShowYourName();
      cout<<"salary: "<<GetPay()<<endl<<endl;
   }

};
class SalesWorker : public PermanentWorker
{
private:
    int salesResult; // 판매 실적
    double bonusRatio; // 보너스 비율
public :
    SalesWorker(string name, int money, double Ratio) : PermanentWorker(name,money),salesResult(0),bonusRatio(Ratio)
    {
    }
    void AddSalesResult(int value)
    {
        salesResult+=value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
   {
      ShowYourName();
      cout<<"salary: "<<GetPay()<<endl<<endl;
   }

};
class EmployeeHandler
{
private:
   Employee* empList[50];
   int empNum;
public:
   EmployeeHandler() : empNum(0)
   { }
   void AddEmployee(Employee* emp)
   {
      empList[empNum++]=emp;
   }
   void ShowAllSalaryInfo() const
   {
      
      for(int i=0; i<empNum; i++)
         empList[i]->ShowSalaryInfo();
      
   }
   void ShowTotalSalary() const
   {
      int sum=0;
      
      for(int i=0; i<empNum; i++)
         sum+=empList[i]->GetPay();
      
      cout<<"salary sum: "<<sum<<endl;
   }
   ~EmployeeHandler()
   {
      for(int i=0; i<empNum; i++)
         delete empList[i];
   }
};

int main(void)
{
   // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
   EmployeeHandler handler;

   // 정규직 등록
   handler.AddEmployee(new PermanentWorker("KIM", 1000));
   handler.AddEmployee(new PermanentWorker("LEE", 1500));

   // 임시직 등록
   TemporaryWorker * alba=new TemporaryWorker("Jung", 700);
   alba->AddWorkTime(5);   // 5시간 일한결과 등록
   handler.AddEmployee(alba);

   // 영업직 등록
   SalesWorker * seller=new SalesWorker("Hong", 1000, 0.1);
   seller->AddSalesResult(7000);   // 영업실적 7000
   handler.AddEmployee(seller);

   // 이번 달에 지불해야 할 급여의 정보
   handler.ShowAllSalaryInfo();

   // 이번 달에 지불해야 할 급여의 총합
   handler.ShowTotalSalary();
   return 0;
}