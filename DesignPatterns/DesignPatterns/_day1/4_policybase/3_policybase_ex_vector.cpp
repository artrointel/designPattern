// 9_단위전략4
#include <iostream>
using namespace std;

// 메모리 할당 정책을 담은 정책 클래스
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
		// 메모리가 부족합니다. 메모리 할당이 필요합니다.
		// new? malloc? calloc? brk() ? HeapAlloc()? pool
		T* p = alloc.allocate(1);

		// 메모리를 해지해야 한다면
		alloc.deallocate(p);

	}
};

int main()
{
	vector<int, allocator<int> > v;
	v.push_back(20);
}


