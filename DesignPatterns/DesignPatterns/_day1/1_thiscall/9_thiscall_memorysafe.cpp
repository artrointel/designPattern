// 1_thiscall9
#include <iostream>
using namespace std;

class Test
{
	int data;
public:
	void f1() { cout << "f1" << endl; }
	int  f2() { cout << "f2" << endl; return 0; }
	int  f3() { cout << "f3" << endl; return data; } // this->data

													 // 아래 함수는 왜 만들었을까요 ? 잘생각해 보세요
													 // kitkat/native/libs/binder/IInterface.cpp에서
													 //					asBinder 함수..
	int call_f3() { return this ? f3() : 0; }
};

int main()
{
	Test* p1 = 0;// 메모리 할당에 실패 해서 0이 나왔다고 가정
	p1->f1(); // 어떻게 될까요 ? 실행하지 말고 생각해보세요
			  // 원리를 잘생각하세요!
			  // f1( p1 )   => f1( 0 )
	p1->f2(); //?
			  //p1->f3(); 

	p1->call_f3(); // f3()를 직접 호출할때와의 차이점은 ?
}

// null pointer exception이 일어나지 않고도 호출될 수 있다.
// 이런 경우를 if-else / try-catch 없이 간결하게 처리할 수 있다.