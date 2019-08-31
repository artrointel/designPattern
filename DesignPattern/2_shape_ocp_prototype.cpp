// 6_도형편집기.cpp
#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체지향 설계의 개념

// 5. 기능 확장에 열려있고( Open, 기능이 나중에 추가되어도)
//    코드 수정에는 닫혀있어야(Close, 기존 코드는 수정되면안된다)
//    는 원칙(Principle )
//    OCP : 개방 폐쇄의 법칙

//    "다형성은 OCP를 만족하는 좋은 코딩스타일이다"


// 6. Prototype 디자인 패턴 : 기존에 존재하는 객체의 복사본을
//						통해서 객체를 만드는 것
//						Clone()가상함수
//						java의 clonable()함수
//						C#의 IClonable 인터페이스
//			아이폰의 모든 클래스에는 copy함수가 있습니다.


// 7. Refactoring 책에 있는 문구 입니다. 잘 생각해보세요

//    "Replace Typecode With Polymorphism"


class Shape
{
public:
	int type = 0;
	virtual void Draw() { cout << "Shape Draw" << endl; }

	// 자신의 복사본을 만드는 가상함수는 좋을때가 많다.!!
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
			cout << "몇번째 도형을 복사할까요 >> ";

			int k;
			cin >> k;
			// k번째 도형의 복사본을 v에 추가합니다.
			// 어떻게 해야 할까요 ? k번째 도형은 뭘까요 ?

			v.push_back(v[k]->Clone()); // 다형성!!


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
				v[i]->Draw(); // 다형성(Polymorphism)
							  // 동일 함수를 호출하는데 상황(객체)에따라
							  // 다르게 동작(다른함수호출)하는것
		}
	}
}



