// 5_�����Լ��ǿ���3
#include <iostream>
using namespace std;

class A
{
public:
	virtual void foo(int a = 10) { cout << "A " << a << endl; }
};
class B : public A  //����Դϴ�.
{
public:
	virtual void foo(int a = 20) { cout << "B " << a << endl; }
};

int main()
{
	A* p = new B;
	p->foo(); // ��� �����غ�����
			  // B : 10
			  // (*p)[0](p, 10) 

			  // ���� �Լ� : ����ð��� ����
			  // ����Ʈ ���� : �����Ͻð��� �����Ϸ��� ������ Ÿ������
			  //				ä���ش�.

			  // �����Լ������� �ǵ����̸� ����Ʈ ���ڸ� �����������
			  // ����ߴٸ� �����Լ� �����ǽÿ� �������� ����!
}

