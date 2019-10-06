#include<iostream>
using namespace std;

// B. 참조계수

class Cat
{
	char* name;
	int		age;
	int* ref; // 참조계수를 가리킬 변수

public:
	Cat(char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		ref = new int(1); // 한 개를 1로 초기화
	}

	// 참조계수 기반의 복사 생성자
	Cat(const Cat& c)
	{
		// 모든 멤버를 얕은 복사 후에
		name = c.name;
		age = c.age;
		ref = c.ref;
		++(*ref);
	}

	// 참조계수 기법의 소멸자
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