// 책을 의미하는 book 클래스와 전자 책을 의미하는 ebook 클래스를 정의하고자
// 한다. 그런데 전자 책도 책의 일종이므로 다음의 형태로 상속관계를 구성하고자 한다(클래스에 선언되어야 할 멤버변수만 제시)

#include <iostream>
using namespace std;

class book {
private:
  string title; // 책 제목
  string isbn;  // 국제표준도서번호
  int price;   // 책 정가
public:
  book(string a, string b, int c) : title(a), isbn(b), price(c) {
    
  }
};

class ebook : public book {
private:
  string dkey; // 인증키
public:
  ebook(string a, string b, int c, string d) : book(a, b, c), dkey(d) {
    
  }
  void show() {
    
  }
};

int main() { 
  book book1("c++", "111-111", 20000);
  ebook book2("java", "222-222", 20000, "pjhnice");
  return 0;
}

/*
출력 결과 :
c++
111-111
20000

java
222-222
20000
pjhnice
*/