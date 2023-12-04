#include <iostream>
using namespace std;

class point
{
    private :
        int xpos,ypos;
    public:
        point(int x=0, int y=0) :xpos(x), ypos(y){}
        void show() const
        {
            cout<<xpos<<' '<<ypos<<endl;
        }
    
};

template <class T>
// 객체 간의 연산
T Swapdata(T &ref1, T &ref2) {
    T temp = ref1;
    ref1 = ref2;
    ref2 = temp;
};

int main() {
    point p1(10, 5);
    point p2(20, 10);
    Swapdata(p1, p2);
    p1.show();
    p2.show();
    return 0;
}