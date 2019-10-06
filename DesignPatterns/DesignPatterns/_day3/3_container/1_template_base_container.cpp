#include<iostream>
using namespace std;

// ���ø� ����� �����̳�
// ���� : Ÿ�� �������� �پ��,
//			��ü �Ӿƴ϶� ǥ��Ÿ�Ե� ���������ϰ�
//			���� �� ĳ������ �ʿ����.
// 
// ���� : �پ��� Ÿ������ ����ϸ� List�� ���� �ڵ尡 �������̴�. �ڵ� �޸� ����

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