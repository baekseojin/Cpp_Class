/*
Base 클래스를 상속받은 MiddleDrivedOne과 MiddleDrivedTwo가 있고
LastDerived는 MiddleDrivedOne과 MiddleDrivedTwo를 다중상속을 받는다.

LastDerived의 클래스 자료형으로 선언된 ldr 변수는 ComplexFunc()를 실행하는데
SimpleFunc()를 실행하는 라인에서 오류가 발생한다. 

이유는 SimpleFunc()는 Base 클래스의 멤버함수고 Base를 상속받은 
MiddleDrivedOne과 MiddleDrivedTwo 중 어느 클래스의 SimpleFunc()를 상속받고 실행해야 할지 컴파일러가 헷갈리기 때문에 오류가 발생한다. 

해결방안은 Base 앞에 virtual을 붙여서 상속을 받게 되면 Base 클래스 하나를 상속받기 때문에 
따로 Base 두 개가 있는 것이 아닌 Base 클래스 하나를 공유해서 상속받게 된다.

(Virtual 을 붙이면 공유하는 이유 : 그냥 상속받으면 상속을 받을 때마다 새로운 객체가 만들어지는데 가상함수를 상속받으면 가상객체 1개를 상속받음, 그래서 가상함수를 여러 클래스가 상속받아도 가상객체 1개를 상속받는 형식이다)
*/