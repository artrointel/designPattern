#include<iostream>
using namespace std;

// 클래스 안에 포인터 멤버가 있다면
// 디폴트 복사 생성자는 얕은 복사 현상을 일으킨다.
// 복사생성자를 만들어서 해결해야 한다.
// A. 깊은복사 : 포인터가 가리키는 데이터 또한 복사
// B. 참조계수 : 포인터의 얕은 복사 + 참조카운트
// C. 소유권 이전 : 이전 객체의 데이터는 제거하고 현재 객체로 이전
// D. 복사 금지 : 복사생성자를 private으로 구현

class Cat
{
	char* name;
	int		age;

public:
	// 컴파일러가 만들어 준 기본 복사 생성자는 얕은 복사만을 수행하나
	// 아래와 같이 포인터가 가리키는 값도 복사(깊은 복사)하는 것이 더 적합한 의도.
	Cat(char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	/* 복사 생성자 직접 구현 : 깊은 복사
	Cat(const Cat& c)
	{
		// 1. 포인터가 아닌 모든 멤버는 그냥 복사.
		age = c.age;

		// 2. 포인터는 메모리를 새로 할당
		name = new char[strlen(c.name) + 1];

		// 3. 메모리 자체를 복사
		strcpy(name, c.name);
	}
	*/

	~Cat() { delete[] name; }
};

int main(void)
{
	Cat c1("NABI", 2);	// 
	Cat c2 = c1;		// default constructor call
	
	// 런타임 에러: default constructor의 얕은 복사로 인해 소멸자 호출 시 delete를 두번 호출하게 된다.
	return 0;
}