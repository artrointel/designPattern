// 1_thiscall5.cpp
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// 타이머를 사용해서 Clock 클래스를 만들어 봅시다.
#include <map> // C++ map 클래스. 키값으로 data 보관가능.

class Clock; // 클래스 전방선언, Clock의 완전한 선언이 없어도 포인터는 사용가능..!

map<int, Clock*> this_map; // 타이머 id/handle/this 를 보관할 자료구조

class Clock
{
	string name;
public:
	Clock(string s) : name(s) {}

	void Start(int ms)
	{
		int id = IoSetTimer(ms, timerRoutine);

		// static 함수에서 this를 사용하기 위해 자료구조에
		// 보관한다.
		this_map[id] = this;
	}

	// 아래 함수가 static 인 이유를 정확히 아셔야 합니다.
	static void timerRoutine(int id)
	{
		//cout << name << endl; // this->name 이 되어야 합니다.
		// 그런데 this가 없습니다.

		Clock* pThis = this_map[id];

		cout << pThis->name << endl;
	}
};

int main()
{
	Clock c1("AAA");
	Clock c2("BBB");

	c1.Start(500);
	c2.Start(1000); // 1초에 한번씩 이름을 출력해야 합니다.

	IoProcessMessage();
}

