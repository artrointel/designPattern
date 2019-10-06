// 9_단위전략3
#include <iostream>
using namespace std;

// template 기반의 정책 클래스 교체
// 장점 : 정책 함수가 인라인 이므로 성능저하가 없다.
// 단점 : 실행시간 정책 교체가 불가능하다.

// Policy Base(단위 전략 디자인기법)
// 참고 : "Modern C++ Design" 책 참고.

template<typename T, typename ThreadModel = NoLock>
class List : public ThreadModel
{
public:
	void push_front(const T& a)
	{
		Lock();
		//......
		Unlock();
	}
};
// 동기화 정책을 담은 정책 클래스를 설계한다.
// 규칙 : 모든 동기화 정책에는 Lock()/Unlock()이 있어야한다.
class NoLock
{
public:
	inline void Lock() {}
	inline void Unlock() {}
};
class MutexLock
{
public:
	inline void Lock() { cout << "Mutex Lock" << endl; }
	inline void Unlock() { cout << "Mutex Unlock" << endl; }
};
//---------------------------------------------
List<int, NoLock> s1;
List<int, MutexLock> s2;

List<int> st; // 전역변수. 멀티스레드에 안전하지 않다.

int main()
{
	st.push_front(10);
}
