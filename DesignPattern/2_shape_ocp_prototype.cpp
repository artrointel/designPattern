// 6_����������.cpp
#include <iostream>
#include <vector>
using namespace std;

// ���� ������� ���� ��ü���� ������ ����

// 5. ��� Ȯ�忡 �����ְ�( Open, ����� ���߿� �߰��Ǿ)
//    �ڵ� �������� �����־��(Close, ���� �ڵ�� �����Ǹ�ȵȴ�)
//    �� ��Ģ(Principle )
//    OCP : ���� ����� ��Ģ

//    "�������� OCP�� �����ϴ� ���� �ڵ���Ÿ���̴�"


// 6. Prototype ������ ���� : ������ �����ϴ� ��ü�� ���纻��
//						���ؼ� ��ü�� ����� ��
//						Clone()�����Լ�
//						java�� clonable()�Լ�
//						C#�� IClonable �������̽�
//			�������� ��� Ŭ�������� copy�Լ��� �ֽ��ϴ�.


// 7. Refactoring å�� �ִ� ���� �Դϴ�. �� �����غ�����

//    "Replace Typecode With Polymorphism"


class Shape
{
public:
	int type = 0;
	virtual void Draw() { cout << "Shape Draw" << endl; }

	// �ڽ��� ���纻�� ����� �����Լ��� �������� ����.!!
	virtual Shape* Clone() { return new Shape(*this); }
};


class Rect : public Shape
{
public:
	Rect() { type = 1; }
	virtual void Draw() { cout << "Rect Draw" << endl; }

	virtual Shape* Clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	Circle() { type = 2; }
	virtual void Draw() { cout << "Circle Draw" << endl; }

	virtual Shape* Clone() { return new Circle(*this); }
};



class Triangle : public Shape
{
public:
	virtual void Draw() { cout << "Triangle Draw" << endl; }
};

int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);


		else if (cmd == 8)
		{
			cout << "���° ������ �����ұ�� >> ";

			int k;
			cin >> k;
			// k��° ������ ���纻�� v�� �߰��մϴ�.
			// ��� �ؾ� �ұ�� ? k��° ������ ����� ?

			v.push_back(v[k]->Clone()); // ������!!


										/*
										switch( v[k]->type )
										{
										case 1: v.push_back( new Rect(*v[k])); break;
										case 2: v.push_back( new Circle(*v[k])); break;
										}
										*/
		}



		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw(); // ������(Polymorphism)
							  // ���� �Լ��� ȣ���ϴµ� ��Ȳ(��ü)������
							  // �ٸ��� ����(�ٸ��Լ�ȣ��)�ϴ°�
		}
	}
}



