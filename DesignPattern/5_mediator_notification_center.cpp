
#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<map>
using namespace std;

// DIP : Dependency Inversion Principle
//			���� ���� ������ ��Ģ
//			�����ִ� ��ü�� �Ź� polling���� ����
//			callback �Լ� ��� �� �뺸 �޴� ���� ���ٴ� ��Ģ
// 

// ������(Mediator) ����(������ ����X)
// -> �������� ��� ���� ��ü �ڽ� �����ο� ���� Listener�� ������ ������, 
// Mediator�� ��� �� ��ü�� ���� �̺�Ʈ�� �ѵ� ��� �����ϴ� ����
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
			v[i](); // function<>�̹Ƿ� ()�� ȣ��
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
	NotificationCenter nc; // Local Center��� �θ��ô�.

	// �Ʒ�ó�� ������ ���� global Center��� �θ��ô�.
	NotificationCenter* nc2 = &NotificationCenter::defaultCenter();

	nc.addObserver("LOWBATTERY", &foo);
	//nc.addObserver("LOWBATTERY", &goo);
	nc.addObserver("LOWBATTERY", bind(&goo, 5));

	// ���͸� ���°� LOW �� �뺸���͸� ���� �˸�
	nc.postNotificationWithName("LOWBATTERY");

	return 0;
}