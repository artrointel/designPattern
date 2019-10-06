// 6_����������.cpp
#include <iostream>
#include <vector>
using namespace std;

// 8. template method ������ ����
//    ������ ���� ��ü�帧�� �θ� �񰡻��Լ�(public)����
//   �����ϰ� ���ϴ� �κи� �����Լ�ȭ(protected, private)
//   �ؼ� �ڽ��� �����Ҽ� �ְ� �Ѵ�.

//   C++���������� NVI(Non Virtual Interface) ��� �Ѵ�

class Shape
{
public:

	// ������ ���� ��ü �˰��򿡼�(���뼺)
	// ���ϴ� �κ�(������)�� ã�Ƽ� �����Լ��� �̾Ƴ���.
protected:
	virtual void DrawImp()
	{
		cout << "Shape Draw" << endl;
	}

public:
	// �Ʒ� �Լ��� ������ ���� ��ü �帧�� �ִ�.
	// �ڽ��� ������ �ϸ� �ȵȴ�.(�񰡻��Լ���!)
	//final	  // java���� �� �Լ��� �ڽ��� �����Ǹ��ϰ� �Ҷ�
	void Draw()
	{
		cout << "mutex lock" << endl;
		DrawImp();
		cout << "mutex unlock" << endl;
	}

	virtual Shape* Clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	virtual void DrawImp() { cout << "Rect Draw" << endl; }

	virtual Shape* Clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	virtual void DrawImp() { cout << "Circle Draw" << endl; }

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

			v.push_back(v[k]->Clone());
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}



