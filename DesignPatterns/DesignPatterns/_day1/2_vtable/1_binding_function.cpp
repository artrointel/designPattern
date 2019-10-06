// 4_�Լ����ε�
#include <iostream>
using namespace std;

class Animal
{
public:	void Cry() { cout << "Animal Cry" << endl; } // 1
};
class Dog : public Animal
{
	// override : �θ��� �Լ��� �ڽ��� �������ϴ°�.
public:	void Cry() { cout << "Dog Cry" << endl; } // 2
};

int main()
{
	Animal a; a.Cry(); // 1
	Dog    d; d.Cry(); // 2

	Animal* p = 0;
	p = &d; // �θ� �����ͷ� �ڽ��� ����Ű�°� => Upcasting
			//---------------------------------
	int n;
	cin >> n;

	if (n == 0) p = &a;
	//-------------------------
	// ������ �ð��� p�� ������ ����Ű���� �˼� ������ ?
	p->Cry(); // 1 ? 2
}
// p->Cry() �� ��� �Լ��� �����Ұ��ΰ� ? => �Լ����ε�

// 1. static binding : ������ �ð��� ��� �Լ��� ȣ��������
//				�����ϴ°�. ������ ������ Ÿ������ �Լ�������
//				Animal Cry ȣ��
// = early binding ����ӵ��� ������. �� ����
//		C++, C#


// 2. dynamic binding : ������ �ð��� p�� �޸𸮸� �����ϴ�
//				���� �ڵ� ������ �����Ҷ� �޸𸮸� �����ؼ�
//				ȣ��. Dog Cry ȣ��
//	= late binding. ������. ����.
//     java, Objective-C, 
//		C++�� C#�� virtual function






