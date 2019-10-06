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

// List 안에 있는 Node를 가리키는 스마트 포인터
// 목표 : 진짜 포인터처럼 ++, *로 list의 모든 요소를
//			접근할 수 있게 한다.
template<typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first; // 찾았으나 first가 0인 경우 혼동
}

template<typename T>
class Slist_iterator
{
	Node<T>* current;
public:
	inline Slist_iterator(Node<T>* p = 0) : current(p) {}
	// 진짜 포인터처럼 ++, *를 사용할 수 있어야 한다.
	// 연산자 재정의 필요 !
	inline Slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }

	inline bool operator==(const Slist_iterator& p) { return this->current == p.current; }
	inline bool operator!=(const Slist_iterator& p) { return this->current != p.current; }
};


template<typename T>
class Slist
{
	Node<T>* head;
public:
	Slist() : head(0) {}
	void push_front(T n) { head = new Node<T>(n, head); }
	T* front() { return head->data; }

	// 모든 컨테이너 제작자는 자신의 반복자 클래스 이름을
	// iterator라는 미리 약속된 이름으로 외부에 노출한다.
	typedef Slist_iterator<T> iterator;



	// 모든 컨테이너 (list, vector등)의 설계자는 
	// 자신의 시작과 마지막 요소 다음을 가리키는 반복자를
	// 리턴하는 2개의 함수를 제공하기로 약속한다.

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};

int main(void)
{
	Slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	//반복자 덕분에 xfind()로 slist를 검색할 수 있다.
	Slist<int>::iterator p2 = xfind(s.begin(), s.end(), 20);
	cout << *p2 << endl;

	Slist<int>::iterator p = s.begin();	// 이제 p는 포인터처럼 생각하고 사용하시면 됩니다.
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
	return 0;
}