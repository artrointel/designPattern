
#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<map>
using namespace std;

// DIP : Dependency Inversion Principle
//			의존 관계 역전의 법칙
//			관심있는 객체가 매번 polling하지 말고
//			callback 함수 등록 후 통보 받는 것이 좋다는 원칙
// 

// 중재자(Mediator) 패턴(옵저버 패턴X)
// -> 옵저버의 경우 각기 객체 자신 스스로에 대해 Listener를 가지고 있으나, 
// Mediator는 모든 각 객체에 대한 이벤트를 한데 모아 관리하는 구조
class NotificationCenter
{
	typedef function<void()> HANDLER;
	map<string, vector<HANDLER>> notif_map;

public:
	void addObserver(string key, HANDLER handler)
	{
		notif_map[key].push_back(handler);
	}

	void postNotificationWithName(string key)
	{
		vector<HANDLER>& v = notif_map[key];

		for (int i = 0; i < v.size(); i++)
		{
			v[i](); // function<>이므로 ()로 호출
		}
	}


	static NotificationCenter defaultCenter()
	{
		static NotificationCenter center;
		return center;
	}
};

//////////////////////////////////////////////////////////////////////////
void foo() { cout << "foo" << endl; }
void goo(int a) { cout << "goo : " << a << endl; }

int main(void)
{
	NotificationCenter nc; // Local Center라고 부릅시다.

	// 아래처럼 꺼내는 것을 global Center라고 부릅시다.
	NotificationCenter* nc2 = &NotificationCenter::defaultCenter();

	nc.addObserver("LOWBATTERY", &foo);
	//nc.addObserver("LOWBATTERY", &goo);
	nc.addObserver("LOWBATTERY", bind(&goo, 5));

	// 배터리 상태가 LOW 시 통보센터를 통해 알림
	nc.postNotificationWithName("LOWBATTERY");

	return 0;
}