#include<iostream>
using namespace std;

// �ݺ��� : �����̳�(���հ�ü)�� �ڷᱸ���� ������� �����ϰ� ��� ��Ҹ� ����
// �湮�� : �����̳�(���հ�ü)�� �ڷᱸ���� ������� �����ϰ� ��� ��ҿ� "����"�� ����

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
	virtual void visit(T& a) = 0; // �ٽ� : ����Ÿ���� ����
	virtual ~IVisitor() {}
};
// �湮�� ���(�����̳�, ���հ�ü)�� �������̽�

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

	// �Ʒ� �Լ��� �ٽ��Դϴ�. �� �����غ�����.
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



// ��Ҹ� 2��� ����� �湮��
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

	// list �ȿ� �ִ� ��� ��Ҹ� 2��� �ϰ� �ʹ�.
	// 1. ������ �����ϸ鼭 �ϳ��� ���� �� 2�踦 �ؼ� �ٽ� �ֱ�
	// 2. �̷� ���� ���� �Ѵٸ� ����Լ��� �߰�����.
	//		s.twiceAll();

	// 3. �ٸ� �����̳�(vector, queue)������ ���� �Ѵٸ�
	//		s.twiceAll(), v.twiceAll(), q.twiceAll()

	// 4. �湮�� ������ ����Ѵ�.
	TwiceVisitor<int> tv;
	s.accept(&tv);

	ShowVisitor<int> sv;
	s.accept(&sv);

	ZeroVisitor<int> zv;
	s.accept(&zv);
	return 0;
}