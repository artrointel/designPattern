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
		return 0; //처리할 메세지가 없다는 것
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
	virtual void OnLButtonDown() {}
};
map<int, Window*> Window::this_map;


//////////////////////////////////////////////////////////////////////////
//사용자가 만들어야 하는 복잡한 코드를 매크로화 해주자.
#define DECLARE_MESSAGE_MAP()										\
	virtual AFX_MSG* GetMessageMap();

#define BEGIN_MESSAGE_MAP(classname, basename)						\
	AFX_MSG* classname::GetMessageMap()								\
	{																\
		typedef void(basename::*HANDLER)();							\
		static AFX_MSG msgArr[] = {									

#define ADD_MESSAGE(message, function)								\
		{message,	(HANDLER)function},	

#define END_MESSAGE_MAP()											\
		{0,0},														\
		};															\
		return msgArr;												\
	}
//////////////////////////////////////////////////////////////////////////

class MyWindow : public Window
{
public:
	void OnLButtonDown() { cout << "MyWindow LButtonDown" << endl; }

	void foo() { cout << "foo" << endl; }
	DECLARE_MESSAGE_MAP()

};

BEGIN_MESSAGE_MAP(MyWindow, Window)
	ADD_MESSAGE(WM_LBUTTONDOWN, &MyWindow::OnLButtonDown)
	ADD_MESSAGE(WM_KEYDOWN, &MyWindow::foo)
END_MESSAGE_MAP()

int main(void)
{
	MyWindow w1;
	w1.Create();

	IoProcessMessage();
}

