#include<iostream>
using namespace std;

// 1. 인라인 함수는 컴파일 시간 문법이다.
// 2. 인라인 함수라도 함수포인터에 담아서 호출하면 인라인 치환될 수 없다.
int Add1(int a, int b) { return a + b; }
inline	int Add2(int a, int b) { return a + b; }

int main(void)
{
	int n1 = Add1(1, 2);	// 호출
	int n2 = Add2(1, 2);	// 치환

	int(*f)(int, int) = &Add2;

	//	int n;
	//	cin >> n;
	//	if(n == 1) f = &Add1; // 인라인 함수는 함수포인터에 담는 순간 치환되지 않는다.
		// 이 순간 컴파일러는 f가 어느 함수를 가리키는지 알 수 있을까?

	int n3 = f(1, 2);	// runtime에 f()의 대상이 변하므로 compile time 치환이 불가능하다.
}
//////////////////////////////////////////////////////////////////////////
// 리눅스 환경 C/C++ 컴파일러 : gcc
// 윈도우 환경 C/C++ 컴파일러 : cl.exe

// cl test.cpp /FAs /Ob1
//"/FAs" : 현재 소스를 어셈으로 만들어달라는 옵션
//"Ob1" : 인라인 치환 문법을 적용해 달라는 옵션
//
//notepad test.asm으로 확인