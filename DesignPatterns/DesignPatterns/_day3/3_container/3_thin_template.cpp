#include<iostream>
using namespace std;

struct Node
{
	void* data;
	Node* next;
	Node(void* d, Node* n) : data(d), next(n) {}
};

class SlistImpl
{
	Node* head;
public:
	SlistImpl() : head(0) {}
	void push_front(void* n) { head = new Node(n, head); }
	void* front() { return head->data; }
};

// void* ��� �����̳ʸ� �ٷ� ����ϸ� �׻� ĳ������ �ʿ��ؼ� �����ϴ�.
// ĳ���ø� å������ Ŭ���� ���ø��� �ڽ����� ��������.
// "Thin Template" : ��κ��� ���� �θ� ���� å������
//						�ڽ��� ĳ���ø��� å������ ��./
//						template Ŭ����ó�� ���������
//						�ڵ� �޸𸮰� �������� �ʰ� �ϴ� ��� -> ĳ������ ���� �ڽ� Ŭ������ ���� �ڵ� �޸𸮸� ����
//
//	kitkat/core/include/utils/Vector.h ����

template<typename T>
class Slist : public SlistImpl
{
public:
	inline void push_front(const T& a)
	{
		SlistImpl::push_front((void*)a);
	}

	inline T& front()
	{
		T ret = (T)(SlistImpl::front());
		return  ret;
	}
};

int main(void)
{
	Slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;
	return 0;
}