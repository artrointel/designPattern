#include<iostream>
using namespace std;

// 반복자 : 컨테이너(복합객체)의 자료구조에 상관없이 동일하고 모든 요소를 열거
// 방문자 : 컨테이너(복합객체)의 자료구조에 상관없이 동일하게 모든 요소에 "연산"을 수행

template<typename T>
struct Node
{
	int data;
	Node* next;
	Node(int d, Node* n) : data(d), next(n) {}
};

template<typename T>
struct IVisitor
{
	virtual void visit(T& a) = 0; // 핵심 : 인자타입이 참조
	virtual ~IVisitor() {}
};
// 방문의 대상(컨테이너, 복합객체)의 인터페이스

template<typename T>
struct IAcceptor
{
	virtual void accept(IVisitor<T>* p) = 0;
	virtual ~IAcceptor() {}
};


template<typename T>
class Slist : public IAcceptor<T>
{
	Node<T>* head;
public:
	Slist() : head(0) {}
	void push_front(T n) { head = new Node<T>(n, head); }
	T* front() { return head->data; }

	// 아래 함수가 핵심입니다. 잘 생각해보세요.
	void accept(IVisitor<T>* p)
	{
		Node<T>* current = head;
		while (current)
		{
			p->visit(current->data);
			current = current->next;
		}
	}
};



// 요소를 2배로 만드는 방문자
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { a = a * 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { cout << a << endl; }
};

template<typename T>
class ZeroVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { a = 0; }
};

int main(void)
{
	Slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	// list 안에 있는 모든 요소를 2배로 하고 싶다.
	// 1. 루프를 수행하면서 하나씩 꺼낸 후 2배를 해서 다시 넣기
	// 2. 이런 일을 자주 한다면 멤버함수로 추가하자.
	//		s.twiceAll();

	// 3. 다른 컨테이너(vector, queue)에서도 자주 한다면
	//		s.twiceAll(), v.twiceAll(), q.twiceAll()

	// 4. 방문자 패턴을 사용한다.
	TwiceVisitor<int> tv;
	s.accept(&tv);

	ShowVisitor<int> sv;
	s.accept(&sv);

	ZeroVisitor<int> zv;
	s.accept(&zv);
	return 0;
}