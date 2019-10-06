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

template<typename T>
class Slist
{
	Node<T>* head;
public:
	Slist() : head(0) {}
	void push_front(T n) { head = new Node<T>(n, head); }
	T* front() { return head->data; }

	void print() {
		Node<T>* it = head;

		while (it != 0)
		{
			cout << it->data << ", ";
			it = it->next;
		}
		cout << endl;
	}
};

int main(void)
{
	Slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.print();
	return 0;
}