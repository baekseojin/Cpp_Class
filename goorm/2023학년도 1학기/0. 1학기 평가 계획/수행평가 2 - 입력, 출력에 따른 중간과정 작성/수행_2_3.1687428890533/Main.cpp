#include <iostream>
#include <string>
using namespace std;

#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

class Car
{
private:
    string gamerID;
    int fuelGauge;
    int curSpeed;
    int item;
public:
	
    //함수 작성
		void InitMembers(string id, int fuel, int speed) {
			gamerID = id;
			fuelGauge = fuel;
			curSpeed = speed;
			item = 10;
		}
    void Attack(Car& target)
    {
        if(item < 0) return;
        item--;
        target.Break();
    }
    void ShowCarState()
    {
        cout<<gamerID<<' '<<fuelGauge<<' '<<curSpeed<<' '<<item<<endl;
    }
    void Accel()
    {
        if(fuelGauge <= 0)
            return;
        else
            fuelGauge -= FUEL_STEP; 

        if((curSpeed + ACC_STEP) >= MAX_SPD) 
        {
            curSpeed = MAX_SPD; 
            return;
        }
        curSpeed += ACC_STEP; 
    }
    void Break()
    {
        if(curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }
        curSpeed -= BRK_STEP;
    }
};

int main(void)
{
    string ID1, ID2;
    int fuel1, speed1,fuel2, speed2;
    cin>>ID1>>fuel1>>speed1>>ID2>>fuel2>>speed2; 
    Car c1, c2;
    c1.InitMembers(ID1, fuel1, speed1); 
    c2.InitMembers(ID2, fuel2, speed2); 
    c1.Accel(); 
    c1.Accel();
    c1.Accel();
    c2.Accel();
    c2.Accel();
    c2.Accel();
    c1.Attack(c2);
    c1.ShowCarState();
    c2.ShowCarState();
    return 0;
}
