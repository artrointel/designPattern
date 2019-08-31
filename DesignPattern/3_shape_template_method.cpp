// 6_도형편집기.cpp
#include <iostream>
#include <vector>
using namespace std;

// 8. template method 디자인 패턴
//    변하지 않은 전체흐름은 부모가 비가상함수(public)으로
//   제공하고 변하는 부분만 가상함수화(protected, private)
//   해서 자식이 변경할수 있게 한다.

//   C++진영에서는 NVI(Non Virtual Interface) 라고도 한다

class Shape
{
public:

	// 변하지 않은 전체 알고리즘에서(공통성)
	// 변하는 부분(가변성)을 찾아서 가상함수로 뽑아낸다.
protected:
	virtual void DrawImp()
	{
		cout << "Shape Draw" << endl;
	}

public:
	// 아래 함수는 변하지 않은 전체 흐름이 있다.
	// 자식이 재정의 하면 안된다.(비가상함수로!)
	//final	  // java에서 이 함수를 자식이 재정의못하게 할때
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
			cout << "몇번째 도형을 복사할까요 >> ";

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



