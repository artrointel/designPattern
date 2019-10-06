#include<iostream>
using namespace std;

// B. �������

class Cat
{
	char* name;
	int		age;
	int* ref; // ��������� ����ų ����

public:
	Cat(char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		ref = new int(1); // �� ���� 1�� �ʱ�ȭ
	}

	// ������� ����� ���� ������
	Cat(const Cat& c)
	{
		// ��� ����� ���� ���� �Ŀ�
		name = c.name;
		age = c.age;
		ref = c.ref;
		++(*ref);
	}

	// ������� ����� �Ҹ���
	~Cat()
	{
		if (--(*ref) == 0)
		{
			delete[] name;
			delete ref;
		}
	}
};

int main(void)
{
	Cat c1("NABI", 2);
	Cat c2 = c1;

	return 0;
}