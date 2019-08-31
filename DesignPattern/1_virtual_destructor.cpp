#include<iostream>
using namespace std;

// 모든 부모 클래스로 사용되는 클래스는 가상소멸자로 만들어야 한다.
// 인터페이스도 결국 부모로 사용된다.
// 모든 인터페이스의 소멸자는 가상이어야 한다.
class Base
{
public:
	virtual ~Base() { cout << "~Base" << endl; } // 가상함수테이블, 가상함수 테이블을 제거하는 방법도 있다.
};

class Derived : public Base
{

public:
	Derived() { cout << "자원할당" << endl; }
	~Derived() { cout << "자원해지" << endl; } // default로 virtual이 된다.
};


int main(void)
{
	Base* p = new Derived;
	delete p; // virtual ~Base()가 아닌 경우 버그 발생 ! 정적 바인딩이므로, Base의 소멸자만 호출한다.
				// 소멸자가 가상함수가 아니면 정적 바인딩을 하게 된다. 
				// p는 Base타입이므로 Base의 소멸자만 호출

	return 0;
}