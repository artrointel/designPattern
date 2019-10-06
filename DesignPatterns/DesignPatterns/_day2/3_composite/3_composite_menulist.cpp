
#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
using namespace std;

// Composite 패턴 !!

// 복합 객체는 개별 객체 뿐 아니라 복합 객체 자신도 보관한다.
// 복합객체와 개별객체는 동일한 부모가 있어야 한다.
// 복합객체와 개별객체의 사용법이 동일하다.
// 사용법은 부모에 있어야 한다. => command는 부모에 있어야 한다.
// 재귀적 포함을 사용하는 디자인 패턴

#define clrscr() system("cls")

class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {}

	string getTitle() { return title; }

	// 모든 메뉴는 선택될 수 있다. 구현은 자식 메뉴들이
	// 아래 한줄이 없다면 메뉴 선택 시 어떤 종류의 메뉴인지 조사하는 코드가 나오게 됩니다.
	// 다형성 기반의 OCP를 사용할 수 없습니다.
	// "모든 자식의 공통의 특징은 반드시 부모에 있어야 한다." LSP (어제의 draw)
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}
	virtual void command()
	{
		cout << getTitle() << "메뉴가 선택됨" << endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;
public:
	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			clrscr();
			int sz = v.size(); // 하위 메뉴의 갯수

			for (int i = 0; i < sz; i++)
			{
				cout << i + 1 << "." << v[i]->getTitle() << endl;
			}

			cout << sz + 1 << ". 상위 메뉴로" << endl;

			cout << "메뉴를 선택하세요 >> ";
			int cmd;
			cin >> cmd;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			if (cmd == sz + 1)
				return; // 또는 break;
			// 선택한 메뉴를 실행한다.
			// 결국 메뉴에 종류에 상관없이 선택되면 command만 호출해주면 된다.
			// 
			v[cmd - 1]->command();
		}
	}

};

int main(void)
{
	PopupMenu* menubar = new PopupMenu("MenuBar");
	PopupMenu* p1 = new PopupMenu("화면설정");
	PopupMenu* p2 = new PopupMenu("소리설정");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("해상도 변경", 11));
	p1->addMenu(new MenuItem("색상 변경", 12));

	p2->addMenu(new MenuItem("소리 크기 변경", 21));
	p2->addMenu(new MenuItem("음색 변경", 22));

	menubar->command();

	return 0;
}