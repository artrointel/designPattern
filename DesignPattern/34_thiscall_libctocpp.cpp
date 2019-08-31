// 1_thiscall3
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// 스레드 개념을 객체지향으로 만들어 봅시다.
// 아래 클래스가 라이브러리 내부 클래스라고 가정합니다.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 1. 아래 함수가 static 멤버 일수 밖에 없는 이유를
	//    정확히 아셔야 합니다.
	//	  스레드 함수는 반드시 인자로 void* 한개만 있어야 합니다.
	//	  this가 없어야 합니다.

	// 2. this가 없으므로 CreateThread()의 4번째 인자로
	//    this를 전달해서 캐스팅후 사용하는 기술.!!
	static DWORD __stdcall threadMain(void* p)
	{
		// p가 결국 this가 됩니다. 캐스팅후 사용하면 됩니다.
		Thread* self = static_cast<Thread*>(p);

		self->ThreadLoop(); //결국 ThreadLoop(self)가 됩니다.


							//ThreadLoop(); // 가상함수 다시 호출
							// this->ThreadLoop() 즉
							// ThreadLoop( this ) 가 되어야 합니다.
		return 0;
	}

	virtual void ThreadLoop() {} // ThreadLoop(Thread* this)
};

// 빌드하면 에러가 있습니다. 왜 에러일까요 ??
// 잘 생각해보세요..


// 아래 클래스가 라이브러리 사용자 클래스입니다.
class MyThread : public Thread
{
public:
	virtual void ThreadLoop() { cout << "ThreadLoop" << endl; }
};

int main()
{
	MyThread t;
	t.run(); // 이순간 스레드가 생성되어서 


			 // ThreadLoop()가상함수를 실행해야 합니다.
	_getch();
}

