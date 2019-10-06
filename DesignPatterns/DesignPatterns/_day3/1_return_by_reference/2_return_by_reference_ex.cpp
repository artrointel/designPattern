#include<iostream>

using namespace std;

// template으로 Collection(List, Stack등) 을 만들 때
// 제거와 리턴을 동시에 하는 함수를 만들지 않은 이유
// 
// 1. 참조리턴을 통해서 임시객체를 제거하려고..
// 2. 예외 안정성의 강력 보장을 지원하기 위해 - 금요일날!

template<typename T>
class Stack
{
	T buff[10];
	int index;
public:
	Stack() : index(-1) {}
	// void push(T a) {buff[index++] = a;}
	// -> 구조체 등을 값으로(call by value) 받으면 성능 저하가 있다.
	// 참조를 받는게 좋다.
	void push(const T& a) { buff[++index] = a; }
	//T	pop() {return buff[--index]; } // 실제로는 제거된 값을 리턴하면 안되므로 다르게 구현(현재 스택에선 되지만)
	// pop()이 제거와 리턴을 동시에 하면 임시객체의 생성을 막을 수 없다. 즉 최적화할 수 없다.
	// 제거와 리턴을 분리하자.
	void pop() { --index; } // 제거만
	T& top() { return buff[index]; } // 리턴만
	// 데이터가 제거되지 않으므로 참조리턴이 가능하다.
};

int main(void)
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	return 0;
}