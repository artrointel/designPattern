// 1_thiscall3
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// ������ ������ ��ü�������� ����� ���ô�.
// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ������� �����մϴ�.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 1. �Ʒ� �Լ��� static ��� �ϼ� �ۿ� ���� ������
	//    ��Ȯ�� �Ƽž� �մϴ�.
	//	  ������ �Լ��� �ݵ�� ���ڷ� void* �Ѱ��� �־�� �մϴ�.
	//	  this�� ����� �մϴ�.

	// 2. this�� �����Ƿ� CreateThread()�� 4��° ���ڷ�
	//    this�� �����ؼ� ĳ������ ����ϴ� ���.!!
	static DWORD __stdcall threadMain(void* p)
	{
		// p�� �ᱹ this�� �˴ϴ�. ĳ������ ����ϸ� �˴ϴ�.
		Thread* self = static_cast<Thread*>(p);

		self->ThreadLoop(); //�ᱹ ThreadLoop(self)�� �˴ϴ�.


							//ThreadLoop(); // �����Լ� �ٽ� ȣ��
							// this->ThreadLoop() ��
							// ThreadLoop( this ) �� �Ǿ�� �մϴ�.
		return 0;
	}

	virtual void ThreadLoop() {} // ThreadLoop(Thread* this)
};

// �����ϸ� ������ �ֽ��ϴ�. �� �����ϱ�� ??
// �� �����غ�����..


// �Ʒ� Ŭ������ ���̺귯�� ����� Ŭ�����Դϴ�.
class MyThread : public Thread
{
public:
	virtual void ThreadLoop() { cout << "ThreadLoop" << endl; }
};

int main()
{
	MyThread t;
	t.run(); // �̼��� �����尡 �����Ǿ 


			 // ThreadLoop()�����Լ��� �����ؾ� �մϴ�.
	_getch();
}

