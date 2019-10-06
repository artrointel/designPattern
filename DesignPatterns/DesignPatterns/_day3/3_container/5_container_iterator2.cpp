#include<iostream>
using namespace std;

// 템플릿 기반의 컨테이너
// 장점 : 타입 안정성이 뛰어나고,
//			객체 뿐아니라 표준타입도 보관가능하고
//			꺼낼 때 캐스팅이 필요없다.
// 
// 단점 : 다양한 타입으로 사용하면 List의 기계어 코드가 여러개이다. 코드 메모리 증가

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(int d, Node* n) : data(d), next(n) {}
};

// 연산자 재정의는 C++만 가능하다. 함수를 사용해서 이동하자.
// 반복자의 인터페이스 (C#과 타이젠(C++)과 유사하게)

// C# 1.0이 아래처럼 되어 있습니다.
// GetObject()의 결과를 항상 캐스팅해야 합니다.
//struct IEnumerator
//{
//	virtual bool MoveNext() = 0;	// ++
//	virtual object*	 GetObject() = 0;	// * 역참조
//	virtual ~IEnumerator() {}
//};

// C# 2.0 그리고 삼성 타이젠(C#이랑 너무 똑같이 만들어놨어요..)
// 인터페이스도 template으로 만든다.
template<typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;	// ++
	virtual T& GetObject() = 0;	// * 역참조
	virtual ~IEnumerator() {}
};

// slist의 반복자
template<typename T>
class Slist_iterator : public IEnumerator<T>
{
	Node<T>* current;
public:
	Slist_iterator(Node<T>* p = 0) : current(p) {}

	// STL의 연산자 재정의 기술 대신 일반 함수를 사용
	virtual bool MoveNext() // ++연산자를 함수로 바꾼 것
	{
		current = current->next;
		return current;
	}

	virtual T& GetObject() { return current->data; }
};

// 모든 컨테이너는 반복자를 꺼낼 수 있어야 한다.
// 컨테이너의 인터페이스
// IEnumerator : 반복자 인터페이스
// IEnumerable : 컨테이너(복합객체) 인터페이스
template<typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumeratorN() = 0;
	virtual ~IEnumerable() {}

};


template<typename T>
class Slist : public IEnumerable<T>
{
	Node<T>* head;
public:
	Slist() : head(0) {}
	virtual IEnumerator<T>* GetEnumeratorN()
	{
		return new Slist_iterator<T>(head);
	}

	void push_front(T n) { head = new Node<T>(n, head); }
	T* front() { return head->data; }
};

template<typename T>
void xfind(IEnumerator<T>* p)
{
	do
	{
		cout << p->GetObject() << endl;
	} while (p->MoveNext());
}

int main(void)
{
	Slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	IEnumerator<int>* p = s.GetEnumeratorN();
	xfind(p);

	delete p; // 타이젠에서 반복자 사용 후에 반드시 delete해야 합니다.

	// 타이젠2.0 부터는 스마트 포인터의 사용을 권장합니다.
	// UniquePtr<IEnumerator<int>> p2 = s.GetEnumeratorN();
	// p2는 delete하지 않아도 됩니다.
	return 0;
}