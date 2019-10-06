// 8_GUI
// "책임의 전가" 디자인 패턴 Responder chain
// 하나의 이벤트를 여러 곳에서 처리하게 되는 디자인 패턴
// 관찰자 패턴 : 여러 객체(Graph)를 등록한 후
//				 event(table상태 변화)가 발생하면
//				 등록된 모든 객체에 이벤트 전달

//	책임의 전가(Chain Of Responsibility)
//		이벤트 발생 시 첫 번째 책임을 가진 객체에 전달
//		처리하지 않은 경우 다음 객체에 고리를 따라 전달

// 맥/아이폰 개발에 사용하는 Cocoa 라이브러리의 모든 GUI는
// "Responder Chain"이라는 기법이 있다.

// MFC의 메뉴 메세지는 Document클래스->View->Frame->App 순서로 
// 메뉴 이벤트가 전달된다.

#include <iostream>
#include<vector>
#include <map>
#include "../utils/ioacademy.h"
using namespace std;
using namespace ioacademy;

class Window
{
	static map< int, Window* > this_map;

	int hwnd;
	//////////////////////////////////////////////////////////////////////////
	Window* parent;		// 부모는 한 명이다.
	vector<Window*> v;	// 자식은 여러 명이다.
public:
	Window() : parent(0) {}

	void addChild(Window* p)
	{
		v.push_back(p);
		p->parent = this;

		// C함수로 자식윈도우를 붙인다.
		IoAddChild(this->hwnd, p->hwnd);
	}
	//////////////////////////////////////////////////////////////////////////

	void Create()
	{
		hwnd = IoMakeWindow(foo);

		this_map[hwnd] = this;
	}

	static int foo(int id, int msg, int a, int b)
	{
		Window* pThis = this_map[id];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			pThis->FireLButtonDown();
			break;
		case WM_KEYDOWN:
			pThis->OnKeyDown();
			break;
		}
		return 0;
	}
	// 아래 함수가 책임의 전가(Chain Of Responsibility)
	void FireLButtonDown()
	{
		// 내가 먼저 처리를 시도한다.
		if (OnLButtonDown() == true)
			return;		// 처리한 경우 종료한다.

		if (parent != 0)
			parent->FireLButtonDown(); // 재귀적 호출
	}
	virtual bool OnLButtonDown() { return false; }
	virtual void OnKeyDown() {}
};
map< int, Window* > Window::this_map;

class MyWindow : public Window
{
public:
	virtual bool OnLButtonDown()
	{
		cout << "MyWindow LButtonDown" << endl;
		return true;
	}
};

class ImageView : public Window
{
public:
	/*
	virtual bool OnLButtonDown()
	{
		cout << "ImageView LButtonDown" << endl;
		return true;
	}
	*/
};
// 이벤트 가상함수를 구현하지 않으면 부모에게 책임이 전가되고
// false를 반환하면 나 자신도 호출하고 부모에게도 처리를 호출

int main()
{
	MyWindow w1;
	w1.Create();

	ImageView v2;
	v2.Create();

	// w2를 w1의 자식으로 붙인다.
	w1.addChild(&v2);

	IoProcessMessage();
	return 0;
}