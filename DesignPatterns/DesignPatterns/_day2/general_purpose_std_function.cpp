// function, bind<> ����� �ڵ带 �����ϰ� ������
// C++ template Complete GUIDE å 21�� �����ϼ���.

#include<iostream>
#include<functional>

using namespace std;
using namespace std::placeholders;

class Camera
{
public:
	void take() { cout << "Camera take" << endl; }

};

void foo() { cout << "foo" << endl; }
void goo(int a)			{ printf("goo : %d\n", a); }
void hoo(int a, int b)	{ printf("hoo : %d, %d\n", a, b);}
void koo(int a, int b, int c, int d)	{ printf("koo : %d, %d, %d, %d\n", a, b, c, d);}

//////////////////////////////////////////////////////////////////////////
// �̹� C++ǥ�ؿ� ������ �Լ������Ͱ� �ֽ��ϴ�. (������ �Լ������ʹ� ��� �� �� ����ִ�.)
// vc++2010, gcc 4.6 �̻���� ��밡��

int main(void)
{
	function<void()> f;

	/*
	f = &foo;
	f(); // foo()

	f = bind(&goo, 5); // ���ڸ� ����� ����. ���ڵ� ���� �� �ִ�.
	f();

	Camera cam;
	f = bind(&Camera::take, &cam); // cmd(&Camera::take, &cam);
	f();
	*/

	/*
	function<void(int)> f2;
	f2 = &goo;
	f2(5); // ok.. goo(5)
	
	f2 = bind(&hoo, 10, _1); // �ɱ��?
	f2(5); // 5=>_1�� ����, hoo(10, 5)
	*/

	function<void(int,int)> f3;
	f3 = bind(&koo, 5, _2, _1, 3);
	f3(7,9);
	return 0;
}