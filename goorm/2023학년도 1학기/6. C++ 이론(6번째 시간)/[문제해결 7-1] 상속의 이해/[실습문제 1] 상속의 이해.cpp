#include <iostream>
using namespace std;

class SoBase {
private:
  int baseNum;

public:
  SoBase() : baseNum(20) { cout << "SoBase()" << endl; } // 1
  SoBase(int n) : baseNum(n) { cout << "SoBase(int n)" << endl; }
  void ShowBaseData() { cout << baseNum << endl; } // 3
};

class SoDerived : public SoBase {
private:
  int derivNum;

public:
  SoDerived() : derivNum(30) { cout << "SoDerived()" << endl; } // 2
  SoDerived(int n) : derivNum(n) { cout << "SoDerived(int n)" << endl; }
  SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) {
    cout << "SoDerived(int n1, int n2)" << endl;
  }
  void ShowDerivData() {
    ShowBaseData();           // 3
    cout << derivNum << endl; // 4
  }
};

int main(void) {
  SoDerived dr1; // 자식 클래스 생성자를 호출하면 반드시 부모 클래스의
                 // 생성자를 먼저 호출한다
  dr1.ShowDerivData();
  cout << "-------------------" << endl;
  SoDerived dr2(12);
  dr2.ShowDerivData();
  cout << "-------------------" << endl;
  SoDerived dr3(23, 24);
  dr3.ShowDerivData();
  return 0;
};

// 자식 클래스 생성자를 호출하면 반드시 부모 클래스의 생성자를 먼저 호출한다

/* 출력결과

SoBase()
SoDerived()
20
30
---------------------
SoBase()
SoDerived(int n)
20
12
----------------------
SoBase(int n)
SoDerived(int n1, n2)
23
24

*/