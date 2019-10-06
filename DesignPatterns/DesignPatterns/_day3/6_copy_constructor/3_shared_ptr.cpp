#include<iostream>
using namespace std;
// ���� ī��Ʈ�� ���� ����
// ���� ���	: ���� �θ� ���Ǵ� ��� shared_ptr
// �̹� C++ǥ�ؿ� ������� ��� ����Ʈ �����Ͱ� �ֽ��ϴ�.
// #include<memory> 

// ����Ʈ������ ���� �� ��������� �����ϴ� 2���� ���
// 1. ������ �ܺο� ��������� �����ϴ� ���
//		����Ʈ�������� ũ�Ⱑ 8����Ʈ �̻��� �ȴ�.
//		��ü*, �������*
//		C++ ǥ�� shared_ptr<>
//
//		shared_ptr<int> p1; // ok. ���Ÿ�Կ� ��밡��
//
//
// 2. ��ü�ȿ� ��������� �ִ� ���
//		����Ʈ������ ��ü�� ũ��� 4����Ʈ�� �ȴ�.
//		C++ ǥ�ؿ��� �̹���� Ŭ������ ����.
//		��κ��� ���̺귯���� ������ ����
//		�ȵ���̵� : RefBase�� sp<> Ŭ����

//		sp<int> p1 = new int; // error.
//		sp�� ǥ�� Ÿ�Կ��� ��� �Ұ���. RefBase �ڽĸ� ����


template<typename T>
class Ptr
{
	T* obj;
	int* ref;
public:
	Ptr(T* p = 0) : obj(p) { ref = new int(1); }
	Ptr(const Ptr& p)
	{
		obj = p->obj;
		ref = p->ref;
		++(*ref);
	}

	~Ptr()
	{
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};


int main(void)
{
	Ptr<int> p = new int;
	Ptr<int> p2 = p;
	return 0;
}
