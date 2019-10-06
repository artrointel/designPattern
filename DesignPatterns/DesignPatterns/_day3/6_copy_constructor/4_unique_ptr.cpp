#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

// �������		: ����. �θ� ���ȴ�.
// ���� : Overhead�� ���� ���� �ڵ����� �ڿ��� �����ȴ�. 
//			�޸� ũ�� ���� ����.
//			��� �Լ��� inline ġȯ��.
// 
// ���� : ����� ������ �ȵǾ �����ϴ�.
//			������ ����/������ �ʿ��ߴٸ� shared_ptr<>�� �������.
// 
// 
// C++ ǥ��			: unique_ptr<>
// �ȵ���̵� ǥ��	: Unique_Ptr<>
// Ÿ����			: UniquePtr<>
//
// C++98�� ����Ʈ������ �� auto_ptr<>�� ������ �����Դϴ�.(deprecated)
// ���� �ʴٰ� �˷����� ���� ������� unique_ptr<>�� ���Խ��ϴ�.

template<typename T>
class Ptr
{
	T* obj; // Ptr�� T�� ������ ũ�Ⱑ �����ϴ�

	// ����� ���� ����
	Ptr(const Ptr&);
	void operator=(const Ptr&);
public:
	// inline !! ���� ���̰� ����.
	inline Ptr(T* p = 0) : obj(p) {}
	inline ~Ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};


int main(void)
{
	Ptr<int> p = new int;
	*p = 10;
	//Ptr<int> p2 = p1; // ������ Ÿ�� ����
	return 0;
}