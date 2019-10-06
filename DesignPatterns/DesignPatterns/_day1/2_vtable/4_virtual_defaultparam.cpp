// 5_가상함수의원리3
#include <iostream>
using namespace std;

class A
{
public:
	virtual void foo(int a = 10) { cout << "A " << a << endl; }
};
class B : public A  //상속입니다.
{
public:
	virtual void foo(int a = 20) { cout << "B " << a << endl; }
};

int main()
{
	A* p = new B;
	p->foo(); // 결과 예측해보세요
			  // B : 10
			  // (*p)[0](p, 10) 

			  // 가상 함수 : 실행시간에 결정
			  // 디폴트 인자 : 컴파일시간에 컴파일러가 포인터 타입으로
			  //				채워준다.

			  // 가상함수에서는 되도록이면 디폴트 인자를 사용하지말자
			  // 사용했다면 가상함수 재정의시에 변경하지 말자!
}

