// 9_��������4
#include <iostream>
using namespace std;

// �޸� �Ҵ� ��å�� ���� ��å Ŭ����
template<typename T> class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }
};
template<typename T, typename Allocator = allocator<T>>
class vector
{
	Allocator<T> alloc;
public:
	void push_back(const T& a)
	{
		// �޸𸮰� �����մϴ�. �޸� �Ҵ��� �ʿ��մϴ�.
		// new? malloc? calloc? brk() ? HeapAlloc()? pool
		T* p = alloc.allocate(1);

		// �޸𸮸� �����ؾ� �Ѵٸ�
		alloc.deallocate(p);

	}
};

int main()
{
	vector<int, allocator<int> > v;
	v.push_back(20);
}


