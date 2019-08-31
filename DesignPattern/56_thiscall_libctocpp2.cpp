// 1_thiscall5.cpp
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// Ÿ�̸Ӹ� ����ؼ� Clock Ŭ������ ����� ���ô�.
#include <map> // C++ map Ŭ����. Ű������ data ��������.

class Clock; // Ŭ���� ���漱��, Clock�� ������ ������ ��� �����ʹ� ��밡��..!

map<int, Clock*> this_map; // Ÿ�̸� id/handle/this �� ������ �ڷᱸ��

class Clock
{
	string name;
public:
	Clock(string s) : name(s) {}

	void Start(int ms)
	{
		int id = IoSetTimer(ms, timerRoutine);

		// static �Լ����� this�� ����ϱ� ���� �ڷᱸ����
		// �����Ѵ�.
		this_map[id] = this;
	}

	// �Ʒ� �Լ��� static �� ������ ��Ȯ�� �Ƽž� �մϴ�.
	static void timerRoutine(int id)
	{
		//cout << name << endl; // this->name �� �Ǿ�� �մϴ�.
		// �׷��� this�� �����ϴ�.

		Clock* pThis = this_map[id];

		cout << pThis->name << endl;
	}
};

int main()
{
	Clock c1("AAA");
	Clock c2("BBB");

	c1.Start(500);
	c2.Start(1000); // 1�ʿ� �ѹ��� �̸��� ����ؾ� �մϴ�.

	IoProcessMessage();
}

