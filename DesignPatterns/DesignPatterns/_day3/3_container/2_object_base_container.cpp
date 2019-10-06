#include<iostream>
using namespace std;

// �پ��� Ÿ���� �����ϰ� �ϴ� ���
// 1. object*�� �����ϸ� ��� �ڽ��� ������ �� �ִ�.
//		java, C# ��� ������ �θ� ����ߴ� ���
// 
// ���� : template�� �ƴϴ�. �پ��� Ÿ�Կ� ���� List�� ����ϴ�
//			List���� �ڵ�� �Ѱ��̴�. �ڵ�޸� ����.

// ���� : 1. Ÿ�� �������� ��������.
//			�Ǽ��� �߸��� Ÿ���� �־ ������ ���� �ʴ´�.
//
//		  2. ��ü�� �ƴ� �⺻Ÿ��(int ��)�� ���� ���� ����.
//			�⺻ Ÿ�Կ� ���� Wrapper Ŭ������ �ʿ��ϴ�.
//
//		  3. ���� �� �ݵ�� ĳ������ �ʿ��ϴ�.
//	
//	

class Object
{
public:
	virtual ~Object() {}
};

// ���̺귯�� ���� ��� Ŭ������ object�� �ڽ����� ������ ����Ѵ�.
class Point : public Object {};
class Rect : public Object {};
class Dialog : public Object {};

// int�� �����ϴ� Ŭ����
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

// �̱۸���Ʈ
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

	s.push_front(new Integer(10)); // C#�� Boxing����

	//Integer* p = s.front(); // �ɱ�� ? �ݵ�� ĳ���� �ʿ�
	Integer* p = static_cast<Integer*>(s.front()); // �ɱ�� ? �ݵ�� ĳ���� �ʿ� <- Dynamic cast
	cout << p->getValue() << endl;

	return 0;
}