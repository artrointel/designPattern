// function, bind<> 만드는 코드를 공부하고 싶으면
// C++ template Complete GUIDE 책 21장 공부하세요.

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
// 이미 C++표준에 범용적 함수포인터가 있습니다. (범용적 함수포인터는 모든 언어에 다 녹아있다.)
// vc++2010, gcc 4.6 이상부터 사용가능

int main(void)
{
	function<void()> f;

	/*
	f = &foo;
	f(); // foo()

	f = bind(&goo, 5); // 인자를 상수로 고정. 인자도 묶을 수 있다.
	f();

	Camera cam;
	f = bind(&Camera::take, &cam); // cmd(&Camera::take, &cam);
	f();
	*/

	/*
	function<void(int)> f2;
	f2 = &goo;
	f2(5); // ok.. goo(5)
	
	f2 = bind(&hoo, 10, _1); // 될까요?
	f2(5); // 5=>_1로 전달, hoo(10, 5)
	*/

	function<void(int,int)> f3;
	f3 = bind(&koo, 5, _2, _1, 3);
	f3(7,9);
	return 0;
}