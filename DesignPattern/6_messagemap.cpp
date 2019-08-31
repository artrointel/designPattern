//

#include<iostream>
#include<map>
#include"ioacademy.h"
using namespace std;
using namespace ioacademy;

// MFC, QT 등의 GUI라이브러리에서 볼 수 있는 클래스
// 라이브러리가 제공하는 클래스입니다.
class Window;
struct AFX_MSG
{
	int message; // 메세지 번호
	void (Window::* handler)(); // 처리할 함수
};
//////////////////////////////////////////////////////////////////////////

class Window
{
	static map<int, Window*> this_map;	//	MFC, QT등에서 이 자료구조를 핸들맵이라고 부릅니다.
	int hwnd;
public:
	void Create()
	{
		hwnd = IoMakeWindow(foo);
		this_map[hwnd] = this;
	}

	// 아래 가상함수에서 처리할 메세지의 종류를 담은 배열을 리턴해야 합니다.
	virtual AFX_MSG* GetMessageMap()
	{
		return 0; // 처리할 메세지가 없다는 것
	}

	static int foo(int h, int msg, int a, int b)
	{
		Window* pThis = this_map[h];

		if (pThis == 0) return 0;

		//메세지 배열을 얻어옵니다.
		AFX_MSG* arr = pThis->GetMessageMap();
		if (arr == 0) return 0; // 처리할 메세지가 없음

		for (; arr->message; arr++)
		{
			if (arr->message == msg)
			{
				void(Window:: * f)() = arr->handler;
				(pThis->*f)();
			}
		}

		return 0;
	}
};
map<int, Window*> Window::this_map;

// 이제 라이브러리 사용자는 파생클래스를 만들고 원하는 이벤트 처리를 위해 가상함수를 재정의 합니다.
// C# Java C++ 등에서 이런 기법을 널리 사용
class MyWindow : public Window
{
public:
	void OnLButtonDown() { cout << "MyWindow LButtonDown" << endl; }

	void foo() { cout << "foo" << endl; }

	// WM_KEYDOWN 발생 시 foo 호출되게 해보세요
	virtual AFX_MSG* GetMessageMap()
	{
		typedef void(Window:: * HANDLER)();
		static AFX_MSG msgArr[] = {
			{WM_LBUTTONDOWN,	(HANDLER)& MyWindow::OnLButtonDown},
			{WM_KEYDOWN,		(HANDLER)& MyWindow::foo},
			{0,0},

		};
		return msgArr;
	}
};

int main(void)
{
	MyWindow w1;
	w1.Create();

	IoProcessMessage();
}

