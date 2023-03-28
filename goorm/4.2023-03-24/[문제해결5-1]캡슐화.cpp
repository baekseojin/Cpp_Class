// struct : 기본이 public
// class : 기본이 private

#include <iostream>
using namespace std;

class SinivelCap    // 콧물 처치용 캡슐
{
public:
    void Take() const {cout<<"콧물 나음"<<endl;}
};

class SneezeCap    // 재채기 처치용 캡슐
{
public:
    void Take() const {cout<<"재채기 멈춤"<<endl;}
};

class SnuffleCap   // 코막힘 처치용 캡슐
{
public:
    void Take() const {cout<<"코막힘 사라짐"<<endl;}
};

// 새로 만든 클래스
class CONTAC600 {
private:
    SinivelCap cap1;
    SneezeCap cap2;
    SnuffleCap cap3;
public:
    void Take() const { // 안에 있는 내용 바꾸지 못함 (=출력문)
        cap1.Take();
        cap2.Take();
        cap3.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

// void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }


// ** 이거 시험 나올 가능성 높음 ** ↑
// const CONTAC600 &cap : 에서 const는 호출한 클래스(CONTAC600)의 필드가 const고 
// const { cap.Take(); } : 에서 const는 본인이 있는 클래스(ColdPatient)의 필드가 const가 된다


// 캡슐화를 하는 이유 : main에서 3번 호출하는 것보다,  main에서 한 번 호출하고 캡슐화한 클래스에서 호출하는게 더 간편하다
 
int main(void)
{
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);
    return 0;
}