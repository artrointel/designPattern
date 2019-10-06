// 5_가상함수의원리2
#include <iostream>
using namespace std;

class A
{
	int x;
public:
	void foo() { cout << "A foo" << endl; } // 1
};

class B    //  주의 ! 상속아님.!!
{
	int y;
public:
	virtual void goo() { cout << "B goo" << endl; } // 2
};
int main()
{
	A aaa;
	// 관련 없는 타입에 대한 캐스팅!
	B* p = reinterpret_cast<B*>(&aaa);

	p->goo(); // 1 ? 2 잘생각해보세요
			  // (*p)[0](p) 라는 기계어 코드
}
//  foo     goo      결과
// 일반     일반      static 바인딩이므로 goo
// 가상     가상      dynamic 바인딩이므로 foo
// 가상     일반      static 바인딩이므로 goo
// 일반     가상      dynamic 바인딩 - 런타임 에러.

