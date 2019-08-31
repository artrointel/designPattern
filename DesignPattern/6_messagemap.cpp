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
		return 0; // ó���� �޼����� ���ٴ� ��
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
};
map<int, Window*> Window::this_map;

// ���� ���̺귯�� ����ڴ� �Ļ�Ŭ������ ����� ���ϴ� �̺�Ʈ ó���� ���� �����Լ��� ������ �մϴ�.
// C# Java C++ ��� �̷� ����� �θ� ���
class MyWindow : public Window
{
public:
	void OnLButtonDown() { cout << "MyWindow LButtonDown" << endl; }

	void foo() { cout << "foo" << endl; }

	// WM_KEYDOWN �߻� �� foo ȣ��ǰ� �غ�����
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

