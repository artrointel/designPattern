// 5_�����Լ��ǿ���2
#include <iostream>
using namespace std;

class A
{
	int x;
public:
	void foo() { cout << "A foo" << endl; } // 1
};

class B    //  ���� ! ��Ӿƴ�.!!
{
	int y;
public:
	virtual void goo() { cout << "B goo" << endl; } // 2
};
int main()
{
	A aaa;
	// ���� ���� Ÿ�Կ� ���� ĳ����!
	B* p = reinterpret_cast<B*>(&aaa);

	p->goo(); // 1 ? 2 �߻����غ�����
			  // (*p)[0](p) ��� ���� �ڵ�
}
//  foo     goo      ���
// �Ϲ�     �Ϲ�      static ���ε��̹Ƿ� goo
// ����     ����      dynamic ���ε��̹Ƿ� foo
// ����     �Ϲ�      static ���ε��̹Ƿ� goo
// �Ϲ�     ����      dynamic ���ε� - ��Ÿ�� ����.

