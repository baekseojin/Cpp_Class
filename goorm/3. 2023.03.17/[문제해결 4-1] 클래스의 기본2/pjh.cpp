#include <iostream>
using namespace std;

#include <cstring>

namespace CAR_CONST
{
	enum
	{
		ID_LEN		=20,
		MAX_SPD		=200,
		FUEL_STEP	=2,
		ACC_STEP	=10,
		BRK_STEP	=10
	};
}

class Car
{
private:
	char gamerID[20];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(char * ID, int fuel) {
        strcpy(gamerID, ID);
        fuelGauge = fuel; 
        curSpeed = 0;
    };
	void ShowCarState() {
        cout<<"소유자ID: "<<gamerID<<endl;
        cout<<"연료량: "<<fuelGauge<<"%"<<endl;
        cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
    };
	void Accel() {
        curSpeed += 10;
        fuelGauge -= 2;
    };
	void Break() {
        curSpeed -= 10;
    };
};