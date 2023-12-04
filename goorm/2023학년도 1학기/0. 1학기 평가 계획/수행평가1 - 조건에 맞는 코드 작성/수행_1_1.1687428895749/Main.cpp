#include <iostream>
using namespace std;

// 조건 1 : 매개변수의 디폴트 값 사용
int add(int num1=0, int num2=0) {
	return num1+num2;
}

// 조건 3 : 생성자와 소멸자 사용
class Test {
	private:
		int num1;
		int num2;
	public: 
		Test(int n1, int n2) :  num1(n1), num2(n2) {
			cout<<"생성자 호출!!"<<endl;
		}
		~Test() {
			cout<<"소멸자 호출!!"<<endl;
		}
};


class Point {
	private:
		int xpos;
		int ypos;
	public:
		Point(int x, int y) : xpos(x), ypos(y) {
			
		}
		void showPosition() {
			cout<<xpos<<", "<<ypos<<endl;
		}
		// 조건 4 : friend 사용
		friend Point operator+(Point &ref1, Point &ref2);
};

Point operator+(Point &ref1, Point &ref2) {
	Point pos(ref1.xpos + ref2.xpos, ref1.ypos + ref2.ypos);
	return pos;
};


class PointTwo {
	private:
		int xpos;
		int ypos;
	public:
		PointTwo(int n1, int n2) : xpos(n1), ypos(n2) {
			
		}
		PointTwo operator++() {
			xpos += 1;
			ypos += 1;
			// 조건 5 : this 포인터 사용
			return *this;
		}
		void showPosition() {
			cout<<"this 포인터 : "<<xpos<<", "<<ypos<<endl;
		}
};


// 조건 6 : 함수 템플릿 사용
template <typename T>
int templateAdd (T num1, T num2) {
	return num1 + num2;
}



int main() {
	
	int num1 = add(5,3);
	cout<<num1<<endl;

	
	// 조건 2 : 참조자 사용
	int num2 = 10;
	int &ref2 = num2;
	cout<<ref2<<endl;

	
	Test test(1,2);
	
	
	Point pos1(3, 5);
	Point pos2(10, 20);
	Point pos3 = operator+(pos1, pos2);
	pos3.showPosition();
	
	
	PointTwo pos5(5, 10);
	PointTwo pos6 = pos5.operator++();
	pos6.showPosition();
	
	
	int num6 = templateAdd(10, 5);
	cout<<num6<<endl;
	return 0;
}