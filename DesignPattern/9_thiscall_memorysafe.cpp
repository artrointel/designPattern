// 1_thiscall9
#include <iostream>
using namespace std;

class Test
{
	int data;
public:
	void f1() { cout << "f1" << endl; }
	int  f2() { cout << "f2" << endl; return 0; }
	int  f3() { cout << "f3" << endl; return data; } // this->data

													 // �Ʒ� �Լ��� �� ���������� ? �߻����� ������
													 // kitkat/native/libs/binder/IInterface.cpp����
													 //					asBinder �Լ�..
	int call_f3() { return this ? f3() : 0; }
};

int main()
{
	Test* p1 = 0;// �޸� �Ҵ翡 ���� �ؼ� 0�� ���Դٰ� ����
	p1->f1(); // ��� �ɱ�� ? �������� ���� �����غ�����
			  // ������ �߻����ϼ���!
			  // f1( p1 )   => f1( 0 )
	p1->f2(); //?
			  //p1->f3(); 

	p1->call_f3(); // f3()�� ���� ȣ���Ҷ����� �������� ?
}

// null pointer exception�� �Ͼ�� �ʰ� ȣ��� �� �ִ�.
// �̷� ��츦 if-else / try-catch ���� �����ϰ� ó���� �� �ִ�.