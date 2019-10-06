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

// void* 기반 컨테이너를 바로 사용하면 항상 캐스팅이 필요해서 불편하다.
// 캐스팅만 책임지는 클래스 템플릿을 자식으로 도입하자.
// "Thin Template" : 대부분의 일은 부모가 전부 책임지고
//						자식은 캐스팅만을 책임지는 것./
//						template 클래스처럼 사용하지만
//						코드 메모리가 증가하지 않게 하는 기술 -> 캐스팅을 위한 자식 클래스에 대한 코드 메모리만 증가
//
//	kitkat/core/include/utils/Vector.h 참조

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