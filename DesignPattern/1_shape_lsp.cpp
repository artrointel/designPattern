// 6_����������.cpp
#include <iostream>
#include <vector>
using namespace std;

// ���� ������� ���� ��ü���� ������ ����

// 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 2. ��� ������ ������ �θ� �����ϸ� ��� ������ ���
//    ���� �Ҽ� �ִ�.

// 3. ��� ������ ������ Ư¡�� �ݵ�� �θ�� ���� �;� �Ѵ�.
//    �׷��� �θ� �����ͷ� �ڽ��� ��� ����Ҷ� �ش� Ư¡��
//    ����Ҽ� �ִ�.
//    LSP : Liskov Substitution Principle

// 4. �θ��� �Լ��� �ڽ��� ������ �ϰ� �ȴٸ�.. �ݵ�� �����Լ�
//    �� ������ �Ѵ�.
//    "�����Լ��� �ƴϸ� ��������������" => Effective C++�ݾ�

class Shape
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
};
class Rect : public Shape
{
public:
	virtual void Draw() { cout << "Rect Draw" << endl; }
};
class Circle : public Shape
{
public:
	virtual void Draw() { cout << "Circle Draw" << endl; }
};

int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		// 1. OCP�� �����ϵ��� ��ü�� �����κ��� ����? Factory ����
		// 2. Undo/Redo ���? Command ����

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}




