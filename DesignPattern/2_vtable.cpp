// 5_�����Լ��� ����
#include <iostream>
using namespace std;

// Base�� ������ �Ҷ� ���� �迭�� �ϳ� ����� �˴ϴ�.
// "Inside C++ Object" ���ͳݿ� EBOOK �ֽ��ϴ�.
void* base_v_table[] = { Base_type_info,
&Base::foo,
&Base::goo };
class Base
{
	void* vtable; // �����Ϸ��� �߰��� ���
	int x;
public:
	Base() { vtable = base_v_table + 4; }
	virtual void foo() {}
	virtual void goo() {}
};
//-----------------------
void* derived_v_table[] = { Derived_type_info,
&Derived::foo, // ������!
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
	p->foo(); // �� ������ ����(���� �ڵ�)�� �����غ��ô�.
			  // (*p)[0](p) ��� ���� �ڵ� ����.
}



