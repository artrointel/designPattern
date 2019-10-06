
#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
using namespace std;

// Composite ���� !!

// ���� ��ü�� ���� ��ü �� �ƴ϶� ���� ��ü �ڽŵ� �����Ѵ�.
// ���հ�ü�� ������ü�� ������ �θ� �־�� �Ѵ�.
// ���հ�ü�� ������ü�� ������ �����ϴ�.
// ������ �θ� �־�� �Ѵ�. => command�� �θ� �־�� �Ѵ�.
// ����� ������ ����ϴ� ������ ����

#define clrscr() system("cls")

class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {}

	string getTitle() { return title; }

	// ��� �޴��� ���õ� �� �ִ�. ������ �ڽ� �޴�����
	// �Ʒ� ������ ���ٸ� �޴� ���� �� � ������ �޴����� �����ϴ� �ڵ尡 ������ �˴ϴ�.
	// ������ ����� OCP�� ����� �� �����ϴ�.
	// "��� �ڽ��� ������ Ư¡�� �ݵ�� �θ� �־�� �Ѵ�." LSP (������ draw)
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}
	virtual void command()
	{
		cout << getTitle() << "�޴��� ���õ�" << endl;
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
			int sz = v.size(); // ���� �޴��� ����

			for (int i = 0; i < sz; i++)
			{
				cout << i + 1 << "." << v[i]->getTitle() << endl;
			}

			cout << sz + 1 << ". ���� �޴���" << endl;

			cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			cin >> cmd;

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			if (cmd == sz + 1)
				return; // �Ǵ� break;
			// ������ �޴��� �����Ѵ�.
			// �ᱹ �޴��� ������ ������� ���õǸ� command�� ȣ�����ָ� �ȴ�.
			// 
			v[cmd - 1]->command();
		}
	}

};

int main(void)
{
	PopupMenu* menubar = new PopupMenu("MenuBar");
	PopupMenu* p1 = new PopupMenu("ȭ�鼳��");
	PopupMenu* p2 = new PopupMenu("�Ҹ�����");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("�ػ� ����", 11));
	p1->addMenu(new MenuItem("���� ����", 12));

	p2->addMenu(new MenuItem("�Ҹ� ũ�� ����", 21));
	p2->addMenu(new MenuItem("���� ����", 22));

	menubar->command();

	return 0;
}