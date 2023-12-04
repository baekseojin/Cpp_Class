#include <iostream>
using namespace std;

class car {
private:
  int gasoline;

public:
  car(int a) : gasoline(a) {}
  int getgas() { return gasoline; }
};

class hybridcar : public car {
private:
  int electric;

public:
  hybridcar(int a, int b) : car(a), electric(b) {}
  int getelec() { return electric; }
};

class hybridwatercar : public hybridcar {
private:
  int watergauge;

public:
  hybridwatercar(int a, int b, int c) : hybridcar(a, b), watergauge(c) {}

  void show() {
    cout << getgas() << endl;   // 79
    cout << getelec() << endl;  // 65
    cout << watergauge << endl; // 35
  }
};

int main() {
  hybridwatercar car1(79, 65, 35);
  car1.show();
  return 0;
}