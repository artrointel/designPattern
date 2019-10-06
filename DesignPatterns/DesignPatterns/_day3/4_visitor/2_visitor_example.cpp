#include<iostream>
#include<string>
#include<vector>
#include <conio.h>
using namespace std;

// list�� �ƴ϶� ���հ�ü(Folder, PopupMenu) ��� �ݺ���, �湮�������� ������ �� �ֽ��ϴ�.
// PopupMenu�� ��� �޴��� �����ϴ� �湮��
class PopupMenu;
class MenuItem;

// �湮�� ������ ����
// 1. ���ο� �޴��� �߰��ϱ� ��������ϴ�.
//		ContextMenu ��� ���ο� �޴��� �߰��Ǹ�
//		�Ʒ� �������̽��� �����˴ϴ�. -> ��� �湮�� �ٽ� �ۼ��ؾ� �մϴ�.
// 2. �������п� ����˴ϴ�. 

struct IMenuVisitor
{
	virtual void visit(PopupMenu* p) = 0;
	virtual void visit(MenuItem* p) = 0;
	virtual ~IMenuVisitor(){}
};

// �޴��� �湮�� ����Դϴ�.
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
	void setTitle(string s) { title = s; } // ���� ���� ����
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void accept( IMenuVisitor* p) 
	{
		// �湮�ڿ��� �ڽ��� �����Ѵ�.
		p->visit(this);
	}
	virtual void command()
	{
		cout << getTitle() << " �޴��� ���õ�.." << endl;
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
		// �湮�ڿ��� �ڽ��� �����Ѵ�.
		p->visit(this);

		// ���� �޴��� ���� �湮�ڿ��� ���� �ش�.
		for ( int i = 0; i < v.size(); i++ )
			v[i]->accept(p);
	}

	void addMenu(BaseMenu* p)  { v.push_back(p); }
	virtual void command()
	{
		while(1)
		{
			clrscr();
			int sz = v.size(); // ���� �޴��� ����
			for( int i = 0; i < sz; i++)
				cout << i+1 << ". " << v[i]->getTitle() <<endl;

			cout << sz+1 << ". ���� �޴���" << endl;
			cout << "�޴��� �����ϼ��� >> ";
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
	PopupMenu* p1 = new PopupMenu("ȭ�鼳��");
	PopupMenu* p2 = new PopupMenu("�Ҹ�����");

	menubar->addMenu(p1);
	p1->addMenu(p2);

	p1->addMenu( new MenuItem("�ػ� ����",11));
	p1->addMenu( new MenuItem("���� ����",  12));
	p1->addMenu( new MenuItem("��� ����",  13));

	p2->addMenu( new MenuItem("�Ҹ� ũ�� ����",21));
	p2->addMenu( new MenuItem("���� ����",22));

	MenuTitleDecorateVisitor mv;
	menubar->accept(&mv); // �˾��޴��� Ÿ��Ʋ�� �����ϴ�
	// �湮��
	// ���� �����Ϸ���??
	menubar->command();

	return 0;
}