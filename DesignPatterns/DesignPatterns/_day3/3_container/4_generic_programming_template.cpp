#include<iostream>
using namespace std;

// 아래처럼 만들면 2개의 문제가 있습니다.
//		1. 구간의 타입과 찾는 요소의 타입이 연관됩니다.
//			double 배열에서 int를 찾을 수 없습니다.
//		2. T*라고 하면 반드시 포인터만 사용해야 합니다.
//			스마트포인터를 사용할 수 없습니다. (스마트포인터는 포인터형이 아닌 객체이기 때문)
// template<typename T>
// T* xfind(T* first, T* last, T value) // (body 구현은 동일)

// 결국 아래처럼 만들어야 합니다.
// 아래 함수는 [fist, last) 사이의 모든 타입의 배열에서 선형검색 수행
// 찾지 못할 경우 last를 리턴
// 아래 함수는 C++ 표준(STL) find()함수와 동일합니다.
template<typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first; // 찾았으나 first가 0인 경우 혼동
}

int main(void)
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = xfind(x, x + 10, 3);
	
	if (p == x + 10)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;

	return 0;
}