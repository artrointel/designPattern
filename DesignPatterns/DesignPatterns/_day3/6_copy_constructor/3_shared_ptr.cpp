#include<iostream>
using namespace std;
// 참조 카운트를 직접 수행
// 참조 계수	: 가장 널리 사용되는 기술 shared_ptr
// 이미 C++표준에 참조계수 기반 스마트 포인터가 있습니다.
// #include<memory> 

// 스마트포인터 만들 때 참조계수를 관리하는 2가지 방식
// 1. 별도로 외부에 참조계수를 관리하는 기법
//		스마트포인터의 크기가 8바이트 이상이 된다.
//		객체*, 참조계수*
//		C++ 표준 shared_ptr<>
//
//		shared_ptr<int> p1; // ok. 모든타입에 사용가능
//
//
// 2. 객체안에 참조계수를 넣는 방식
//		스마트포인터 자체의 크기는 4바이트면 된다.
//		C++ 표준에는 이방식의 클래스는 없다.
//		대부분의 라이브러리가 별도로 지원
//		안드로이드 : RefBase와 sp<> 클래스

//		sp<int> p1 = new int; // error.
//		sp는 표준 타입에는 사용 불가능. RefBase 자식만 가능


template<typename T>
class Ptr
{
	T* obj;
	int* ref;
public:
	Ptr(T* p = 0) : obj(p) { ref = new int(1); }
	Ptr(const Ptr& p)
	{
		obj = p->obj;
		ref = p->ref;
		++(*ref);
	}

	~Ptr()
	{
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};


int main(void)
{
	Ptr<int> p = new int;
	Ptr<int> p2 = p;
	return 0;
}
