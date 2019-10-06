// 3_접근변경자2
#include <iostream>
using namespace std;

// 왜 private 상속을 사용하는가 ? 

// 부모로 부터 구현은 물려 받지만(자식이 부모 함수를 사용하지만)
// 인터페이스를 물려 받지는 않겠다.( 부모 함수를 외부 노출
//								하지는 않겠다는것)


// list가 이미 있습니다.
#include <list>

// 그런데 stack이 필요합니다.
// 1. stack을 다시 만들자
// 2. list를 한쪽으로만 사용하면 stack처럼 보인다. list를
//    재사용하자.

// Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서
//				 클라이언트가 요구하는 새로운 클래스를
//				 제공하는 것!
// 아래 처럼 만들면 메모리사용량증가나 성능의 저하가 전혀없이
// 새로운 클래스를 제공할수도 있게 된다.
/*
template<typename T> class stack : private list<T> // private 상속
{
public:
inline void push( const T& a ) { list<T>::push_back(a); }
inline T&   top()              { return list<T>::back(); }
inline void pop()              { list<T>::pop_back(); }
};
*/
// Java 등에서는 상속관계인경우 list 클래스의 인터페이스가 노출되는 문제가 발생한다.

// S/W의 재사용은 상속과 포함이 있다. - 포함이 좋을때가 더많다

#include <vector>
#include <deque>  // list와 vector의 절충..
// 연속된 메모리를 다시 list로
template<typename T, typename C = deque<T>> class stack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline T&   top() { return st.back(); }
	inline void pop() { st.pop_back(); }
};

#include <stack> // C++ 표준인 STL의 stack 클래스
// 흔히 "stack adapter" 라고 부릅니다.
// 구현은 위와 유사합니다.
int main()
{
	stack<int, list<int>> s1;
	stack<int, vector<int>> s2;

	stack<int> s;
	s.push(10);
	s.push(20);
	// s.push_front(30); // (잘못된 사용 가능성 -> private 상속)
}



