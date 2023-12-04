#include <iostream>
using namespace std;

class rectangle {
private:
  int garo;
  int sero;

public:
  rectangle(int a, int b) : garo(a), sero(b) {}

  void show() { 
    cout << garo * sero << endl;
  }
};

class square : public rectangle {

public:
  square(int a) : rectangle(a, a) {}
};

// 이에 다음 main 함수와 함께 <출력결과>가 나오도록 위의 클래스를 완성하시오.

int main(void)

{
  rectangle rec(4, 3);
  rec.show();

  square sqr(7);
  sqr.show();
  return 0;
}

// 출력결과 : 12 49