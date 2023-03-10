int f(int a=10)

{

     return a+1;

}

int f(void)

{

     return 10;

}

/*
int f() 로 함수를 호출하면 반환형이 int인 f() 함수를 디폴트값을 사용하는 형태로 호출하려고 하는지, 
아니면 반환형이 void인 f() 함수를 호출하려고 하는지 구분이 되지 않기 때문이다.   
*/