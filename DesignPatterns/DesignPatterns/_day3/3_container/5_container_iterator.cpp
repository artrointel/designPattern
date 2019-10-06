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

// List �ȿ� �ִ� Node�� ����Ű�� ����Ʈ ������
// ��ǥ : ��¥ ������ó�� ++, *�� list�� ��� ��Ҹ�
//			������ �� �ְ� �Ѵ�.
template<typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first; // ã������ first�� 0�� ��� ȥ��
}

template<typename T>
class Slist_iterator
{
	Node<T>* current;
public:
	inline Slist_iterator(Node<T>* p = 0) : current(p) {}
	// ��¥ ������ó�� ++, *�� ����� �� �־�� �Ѵ�.
	// ������ ������ �ʿ� !
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

	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� Ŭ���� �̸���
	// iterator��� �̸� ��ӵ� �̸����� �ܺο� �����Ѵ�.
	typedef Slist_iterator<T> iterator;



	// ��� �����̳� (list, vector��)�� �����ڴ� 
	// �ڽ��� ���۰� ������ ��� ������ ����Ű�� �ݺ��ڸ�
	// �����ϴ� 2���� �Լ��� �����ϱ�� ����Ѵ�.

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};

int main(void)
{
	Slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	//�ݺ��� ���п� xfind()�� slist�� �˻��� �� �ִ�.
	Slist<int>::iterator p2 = xfind(s.begin(), s.end(), 20);
	cout << *p2 << endl;

	Slist<int>::iterator p = s.begin();	// ���� p�� ������ó�� �����ϰ� ����Ͻø� �˴ϴ�.
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
	return 0;
}