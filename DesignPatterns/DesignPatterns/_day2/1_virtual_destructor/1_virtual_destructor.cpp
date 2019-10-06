#include<iostream>
using namespace std;

// ��� �θ� Ŭ������ ���Ǵ� Ŭ������ ����Ҹ��ڷ� ������ �Ѵ�.
// �������̽��� �ᱹ �θ�� ���ȴ�.
// ��� �������̽��� �Ҹ��ڴ� �����̾�� �Ѵ�.
class Base
{
public:
	virtual ~Base() { cout << "~Base" << endl; } // �����Լ����̺�, �����Լ� ���̺��� �����ϴ� ����� �ִ�.
};

class Derived : public Base
{

public:
	Derived() { cout << "�ڿ��Ҵ�" << endl; }
	~Derived() { cout << "�ڿ�����" << endl; } // default�� virtual�� �ȴ�.
};


int main(void)
{
	Base* p = new Derived;
	delete p; // virtual ~Base()�� �ƴ� ��� ���� �߻� ! ���� ���ε��̹Ƿ�, Base�� �Ҹ��ڸ� ȣ���Ѵ�.
				// �Ҹ��ڰ� �����Լ��� �ƴϸ� ���� ���ε��� �ϰ� �ȴ�. 
				// p�� BaseŸ���̹Ƿ� Base�� �Ҹ��ڸ� ȣ��

	return 0;
}