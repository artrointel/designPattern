// 5_가상함수의 원리
#include <iostream>
using namespace std;

// Base를 컴파일 할때 전역 배열을 하나 만들게 됩니다.
// "Inside C++ Object" 인터넷에 EBOOK 있습니다.
void* base_v_table[] = { Base_type_info,
&Base::foo,
&Base::goo };
class Base
{
	void* vtable; // 컴파일러가 추가한 멤버
	int x;
public:
	Base() { vtable = base_v_table + 4; }
	virtual void foo() {}
	virtual void goo() {}
};
//-----------------------
void* derived_v_table[] = { Derived_type_info,
&Derived::foo, // 재정의!
&Base::goo };

class Derived : public Base
{
	void* vtable;
	int y;
public:
	Derived() { vtable = derived_v_table + 4; }
	virtual void foo() {}
};
int main()
{
	Base b;    cout << sizeof(b) << endl; // 8
	Derived d; cout << sizeof(d) << endl; // 12

	Base* p = &d;
	p->foo(); // 이 한줄의 원리(기계어 코드)를 생각해봅시다.
			  // (*p)[0](p) 라는 기계어 코드 생성.
}



