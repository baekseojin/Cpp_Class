#include <iostream>
using namespace std;

class myfriend {
private:
  string name;
  int age;

public:
  myfriend(string a, int b) : name(a), age(b) {}
  ~myfriend() {
    
  }
  void show() {
    cout << name << endl;
    cout << age << endl;
  }
};
class myfriendinfo : public myfriend {
private:
  string addr;
  string phone;

public:
  myfriendinfo(string a, int b, string c, string d)
      : myfriend(a, b), addr(c), phone(d) {}

  ~myfriendinfo() {
    
  }
  void showinfo() {
    show();
    cout << addr << endl;
    cout << phone << endl;
  }
};

int main() {
  myfriendinfo p1("박제현", 20, "해운대", "1671");
  myfriendinfo p2("박지성", 30, "동래", "7777");
  p1.showinfo();
  p2.showinfo();
  return 0;
}