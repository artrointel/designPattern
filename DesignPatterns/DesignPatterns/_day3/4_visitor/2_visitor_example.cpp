#include<iostream>
#include<string>
#include<vector>
#include <conio.h>
using namespace std;

// list뿐 아니라 복합객체(Folder, PopupMenu) 등에도 반복자, 방문자패턴을 적용할 수 있습니다.
// PopupMenu의 모든 메뉴를 조작하는 방문자
class PopupMenu;
class MenuItem;

// 방문자 패턴의 단점
// 1. 새로운 메뉴를 추가하기 어려워집니다.
//		ContextMenu 라는 새로운 메뉴가 추가되면
//		아래 인터페이스가 수정됩니다. -> 모든 방문자 다시 작성해야 합니다.
// 2. 정보은닉에 위배됩니다. 

struct IMenuVisitor
{
	virtual void visit(PopupMenu* p) = 0;
	virtual void visit(MenuItem* p) = 0;
	virtual ~IMenuVisitor(){}
};

// 메뉴는 방문의 대상입니다.
struct IMenuAcceptor
{
	virtual void accept(IMenuVisitor* p)  = 0;
	virtual ~IMenuAcceptor() {}
};

#define clrscr() system("cls");

class BaseMenu : public IMenuAcceptor
{
	string title;
public:
	BaseMenu(string s) : title(s) {}
	string getTitle() {return title;}
	void setTitle(string s) { title = s; } // 정보 은닉 실패
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void accept( IMenuVisitor* p) 
	{
		// 방문자에게 자신을 전달한다.
		p->visit(this);
	}
	virtual void command()
	{
		cout << getTitle() << " 메뉴가 선택됨.." << endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;
public:
	PopupMenu(string s) : BaseMenu(s) {}

	virtual void accept(IMenuVisitor* p)
	{
		// 방문자에게 자신을 전달한다.
		p->visit(this);

		// 하위 메뉴를 전부 방문자에게 보내 준다.
		for ( int i = 0; i < v.size(); i++ )
			v[i]->accept(p);
	}

	void addMenu(BaseMenu* p)  { v.push_back(p); }
	virtual void command()
	{
		while(1)
		{
			clrscr();
			int sz = v.size(); // 하위 메뉴의 갯수
			for( int i = 0; i < sz; i++)
				cout << i+1 << ". " << v[i]->getTitle() <<endl;

			cout << sz+1 << ". 상위 메뉴로" << endl;
			cout << "메뉴를 선택하세요 >> ";
			int cmd;
			cin >> cmd;


			if ( cmd < 1 || cmd > sz+1) 
				continue;

			if ( cmd == sz+1)  
				break; 

			v[cmd-1]->command();
		}
	}
};

class MenuTitleDecorateVisitor : public IMenuVisitor
{
public:
	virtual void visit(PopupMenu* p)
	{
		string s = p->getTitle();
		string s2 = "[" + s + "]";
		p->setTitle(s2);
	}

	virtual void visit(MenuItem* p)
	{

	}
};

template<typename T>
class TwiceVisitor : public IMenuVisitor
{
public:
	virtual void visit(T& a) { a = a * 2; }
};

template<typename T>
class ShowVisitor : public IMenuVisitor
{
public:
	virtual void visit(T& a) { cout << a << endl; }
};

template<typename T>
class ZeroVisitor : public IMenuVisitor
{
public:
	virtual void visit(T& a) { a = 0; } 
};

int main(void)
{
	PopupMenu* menubar = new PopupMenu("MenuBar");
	PopupMenu* p1 = new PopupMenu("화면설정");
	PopupMenu* p2 = new PopupMenu("소리설정");

	menubar->addMenu(p1);
	p1->addMenu(p2);

	p1->addMenu( new MenuItem("해상도 변경",11));
	p1->addMenu( new MenuItem("색상 변경",  12));
	p1->addMenu( new MenuItem("명암 변경",  13));

	p2->addMenu( new MenuItem("소리 크기 변경",21));
	p2->addMenu( new MenuItem("음색 변경",22));

	MenuTitleDecorateVisitor mv;
	menubar->accept(&mv); // 팝업메뉴의 타이틀을 조작하는
	// 방문자
	// 이제 시작하려면??
	menubar->command();

	return 0;
}