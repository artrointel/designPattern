
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 메뉴를 선택할 때 이벤트 처리 기술을 생각해 봅시다.
// 1. 인터페이스 기반 리스너 개념 : Java, 안드로이드, 타이젠
// 메뉴를 처리하고 싶은 모든 모든 객체는 아래 인터페이스를 구현해야 한다.
struct IMenuListener
{
	// 리스너에 함수는 반드시 인자로 id 값 또는 MenuItem* 등이 있어야 한다.
	virtual void onCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem
{
	int id;
	vector<IMenuListener*> v;
public:
	MenuItem(int n) : id(n) {}
	void addListener(IMenuListener* p) { v.push_back(p); }
	void command()
	{
		// 메뉴가 선택된 사실을 외부에 알려야 한다.
		// 관찰자 패턴 : 하나의 이벤트를 등록된 여러객체로 전달하는 패턴
		int size = v.size();
		for (int i = 0; i < size; i++)
			v[i]->onCommand(id);
	}
};

//////////////////////////////////////////////////////////////////////////

class Camera : public IMenuListener
{
public:
	void onCommand(int id)
	{
		// 메뉴 id에 따라서 원하는 기능 수행 ! <- switch가 나와야 하네요.
		switch (id)
		{
		case 11: break;
		case 12: break;
		}
		cout << "Camera onCommand" << endl;
	}
};

int main(void)
{
	Camera cam;
	MenuItem m1(11);
	MenuItem m2(12);
	m1.addListener(&cam);
	m2.addListener(&cam);
	m1.command();
	return 0;
}