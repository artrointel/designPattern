// 8_GUI
// "å���� ����" ������ ���� Responder chain
// �ϳ��� �̺�Ʈ�� ���� ������ ó���ϰ� �Ǵ� ������ ����
// ������ ���� : ���� ��ü(Graph)�� ����� ��
//				 event(table���� ��ȭ)�� �߻��ϸ�
//				 ��ϵ� ��� ��ü�� �̺�Ʈ ����

//	å���� ����(Chain Of Responsibility)
//		�̺�Ʈ �߻� �� ù ��° å���� ���� ��ü�� ����
//		ó������ ���� ��� ���� ��ü�� ���� ���� ����

// ��/������ ���߿� ����ϴ� Cocoa ���̺귯���� ��� GUI��
// "Responder Chain"�̶�� ����� �ִ�.

// MFC�� �޴� �޼����� DocumentŬ����->View->Frame->App ������ 
// �޴� �̺�Ʈ�� ���޵ȴ�.

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
	Window* parent;		// �θ�� �� ���̴�.
	vector<Window*> v;	// �ڽ��� ���� ���̴�.
public:
	Window() : parent(0) {}

	void addChild(Window* p)
	{
		v.push_back(p);
		p->parent = this;

		// C�Լ��� �ڽ������츦 ���δ�.
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
	// �Ʒ� �Լ��� å���� ����(Chain Of Responsibility)
	void FireLButtonDown()
	{
		// ���� ���� ó���� �õ��Ѵ�.
		if (OnLButtonDown() == true)
			return;		// ó���� ��� �����Ѵ�.

		if (parent != 0)
			parent->FireLButtonDown(); // ����� ȣ��
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
// �̺�Ʈ �����Լ��� �������� ������ �θ𿡰� å���� �����ǰ�
// false�� ��ȯ�ϸ� �� �ڽŵ� ȣ���ϰ� �θ𿡰Ե� ó���� ȣ��

int main()
{
	MyWindow w1;
	w1.Create();

	ImageView v2;
	v2.Create();

	// w2�� w1�� �ڽ����� ���δ�.
	w1.addChild(&v2);

	IoProcessMessage();
	return 0;
}