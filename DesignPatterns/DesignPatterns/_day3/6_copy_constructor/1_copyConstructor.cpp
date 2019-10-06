#include<iostream>
using namespace std;

// Ŭ���� �ȿ� ������ ����� �ִٸ�
// ����Ʈ ���� �����ڴ� ���� ���� ������ ����Ų��.
// ��������ڸ� ���� �ذ��ؾ� �Ѵ�.
// A. �������� : �����Ͱ� ����Ű�� ������ ���� ����
// B. ������� : �������� ���� ���� + ����ī��Ʈ
// C. ������ ���� : ���� ��ü�� �����ʹ� �����ϰ� ���� ��ü�� ����
// D. ���� ���� : ��������ڸ� private���� ����

class Cat
{
	char* name;
	int		age;

public:
	// �����Ϸ��� ����� �� �⺻ ���� �����ڴ� ���� ���縸�� �����ϳ�
	// �Ʒ��� ���� �����Ͱ� ����Ű�� ���� ����(���� ����)�ϴ� ���� �� ������ �ǵ�.
	Cat(char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	/* ���� ������ ���� ���� : ���� ����
	Cat(const Cat& c)
	{
		// 1. �����Ͱ� �ƴ� ��� ����� �׳� ����.
		age = c.age;

		// 2. �����ʹ� �޸𸮸� ���� �Ҵ�
		name = new char[strlen(c.name) + 1];

		// 3. �޸� ��ü�� ����
		strcpy(name, c.name);
	}
	*/

	~Cat() { delete[] name; }
};

int main(void)
{
	Cat c1("NABI", 2);	// 
	Cat c2 = c1;		// default constructor call
	
	// ��Ÿ�� ����: default constructor�� ���� ����� ���� �Ҹ��� ȣ�� �� delete�� �ι� ȣ���ϰ� �ȴ�.
	return 0;
}