#include<iostream>
using namespace std;

// 다양한 타입을 저장하게 하는 방법
// 1. object*를 저장하면 모든 자식을 저장할 수 있다.
//		java, C# 등에서 예전에 널리 사용했던 기술
// 
// 장점 : template이 아니다. 다양한 타입에 대해 List를 사용하는
//			List기계어 코드는 한개이다. 코드메모리 감소.

// 단점 : 1. 타입 안정성이 떨어진다.
//			실수로 잘못된 타입을 넣어도 에러가 나지 않는다.
//
//		  2. 객체가 아닌 기본타입(int 등)을 넣을 수가 없다.
//			기본 타입에 대한 Wrapper 클래스가 필요하다.
//
//		  3. 꺼낼 때 반드시 캐스팅이 필요하다.
//	
//	

class Object
{
public:
	virtual ~Object() {}
};

// 라이브러리 내의 모든 클래스는 object의 자식으로 만들기로 약속한다.
class Point : public Object {};
class Rect : public Object {};
class Dialog : public Object {};

// int를 래핑하는 클래스
class Integer : public Object
{
	int value;
public:
	Integer(int n) : value(n) {}
	int getValue() { return value; }
};

struct Node
{
	Object* data;
	Node* next;
	Node(Object* d, Node* n) : data(d), next(n) {}
};

// 싱글리스트
class Slist
{
	Node* head;
public:
	Slist() : head(0) {}

	void push_front(Object* n) { head = new Node(n, head); }
	Object* front() { return head->data; }
};

int main(void)
{
	Slist s;
	s.push_front(new Point);
	s.push_front(new Point);
	s.push_front(new Dialog);

	s.push_front(new Integer(10)); // C#의 Boxing개념

	//Integer* p = s.front(); // 될까요 ? 반드시 캐스팅 필요
	Integer* p = static_cast<Integer*>(s.front()); // 될까요 ? 반드시 캐스팅 필요 <- Dynamic cast
	cout << p->getValue() << endl;

	return 0;
}