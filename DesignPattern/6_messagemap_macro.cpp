//


#include<iostream>
#include<map>
#include"ioacademy.h"
using namespace std;
using namespace ioacademy;

// MFC, QT ���� GUI���̺귯������ �� �� �ִ� Ŭ����
// ���̺귯���� �����ϴ� Ŭ�����Դϴ�.
class Window;
struct AFX_MSG
{
	int message; // �޼��� ��ȣ
	void (Window::* handler)(); // ó���� �Լ�
};
//////////////////////////////////////////////////////////////////////////

class Window
{
	static map<int, Window*> this_map;	//	MFC, QT��� �� �ڷᱸ���� �ڵ���̶�� �θ��ϴ�.
	int hwnd;
public:
	void Create()
	{
		hwnd = IoMakeWindow(foo);
		this_map[hwnd] = this;
	}

	// �Ʒ� �����Լ����� ó���� �޼����� ������ ���� �迭�� �����ؾ� �մϴ�.
	virtual AFX_MSG* GetMessageMap()
	{
		return 0; //ó���� �޼����� ���ٴ� ��
	}

	static int foo(int h, int msg, int a, int b)
	{
		Window* pThis = this_map[h];

		if (pThis == 0) return 0;

		//�޼��� �迭�� ���ɴϴ�.
		AFX_MSG* arr = pThis->GetMessageMap();
		if (arr == 0) return 0; // ó���� �޼����� ����

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
//����ڰ� ������ �ϴ� ������ �ڵ带 ��ũ��ȭ ������.
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

