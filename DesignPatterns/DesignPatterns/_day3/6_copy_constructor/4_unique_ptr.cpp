#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

// 복사금지		: 좋다. 널리 사용된다.
// 장점 : Overhead가 전혀 없이 자동으로 자원이 관리된다. 
//			메모리 크기 또한 같다.
//			모든 함수가 inline 치환됨.
// 
// 단점 : 복사와 대입이 안되어서 불편하다.
//			하지만 복사/대입이 필요했다면 shared_ptr<>을 사용하자.
// 
// 
// C++ 표준			: unique_ptr<>
// 안드로이드 표준	: Unique_Ptr<>
// 타이젠			: UniquePtr<>
//
// C++98의 스마트포인터 중 auto_ptr<>은 소유권 이전입니다.(deprecated)
// 좋지 않다고 알려져서 이제 사라지고 unique_ptr<>이 나왔습니다.

template<typename T>
class Ptr
{
	T* obj; // Ptr과 T의 데이터 크기가 동일하다

	// 복사와 대입 금지
	Ptr(const Ptr&);
	void operator=(const Ptr&);
public:
	// inline !! 성능 차이가 없다.
	inline Ptr(T* p = 0) : obj(p) {}
	inline ~Ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};


int main(void)
{
	Ptr<int> p = new int;
	*p = 10;
	//Ptr<int> p2 = p1; // 컴파일 타임 에러
	return 0;
}