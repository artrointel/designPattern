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

// ������ �����Ǵ� C++�� �����ϴ�. �Լ��� ����ؼ� �̵�����.
// �ݺ����� �������̽� (C#�� Ÿ����(C++)�� �����ϰ�)

// C# 1.0�� �Ʒ�ó�� �Ǿ� �ֽ��ϴ�.
// GetObject()�� ����� �׻� ĳ�����ؾ� �մϴ�.
//struct IEnumerator
//{
//	virtual bool MoveNext() = 0;	// ++
//	virtual object*	 GetObject() = 0;	// * ������
//	virtual ~IEnumerator() {}
//};

// C# 2.0 �׸��� �Ｚ Ÿ����(C#�̶� �ʹ� �Ȱ��� ���������..)
// �������̽��� template���� �����.
template<typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;	// ++
	virtual T& GetObject() = 0;	// * ������
	virtual ~IEnumerator() {}
};

// slist�� �ݺ���
template<typename T>
class Slist_iterator : public IEnumerator<T>
{
	Node<T>* current;
public:
	Slist_iterator(Node<T>* p = 0) : current(p) {}

	// STL�� ������ ������ ��� ��� �Ϲ� �Լ��� ���
	virtual bool MoveNext() // ++�����ڸ� �Լ��� �ٲ� ��
	{
		current = current->next;
		return current;
	}

	virtual T& GetObject() { return current->data; }
};

// ��� �����̳ʴ� �ݺ��ڸ� ���� �� �־�� �Ѵ�.
// �����̳��� �������̽�
// IEnumerator : �ݺ��� �������̽�
// IEnumerable : �����̳�(���հ�ü) �������̽�
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

	delete p; // Ÿ�������� �ݺ��� ��� �Ŀ� �ݵ�� delete�ؾ� �մϴ�.

	// Ÿ����2.0 ���ʹ� ����Ʈ �������� ����� �����մϴ�.
	// UniquePtr<IEnumerator<int>> p2 = s.GetEnumeratorN();
	// p2�� delete���� �ʾƵ� �˴ϴ�.
	return 0;
}