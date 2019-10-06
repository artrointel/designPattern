#include<iostream>
using namespace std;
// 인터페이스 기반의 참조카운트 구현
// 단점: 객체 타입만 가능하고 상속받아야 한다.
// 단점: 원시 타입은 사용할 수 없다.(이 경우 wrapper class 구현 및 사용)

class RefBase
{
	int mCount;
public:
	RefBase() : mCount(0) {}
	virtual ~RefBase() { cout << "~RefBase" << endl; }

	void incStrong() { 
		++mCount;
		cout << mCount << endl;
	}

	void decStrong() { if (--mCount == 0) delete this; }
};

template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = 0) : obj(p)
	{
		if (obj) obj->incStrong();
	}

	// T 복사생성자 호출과 참조계수 카운트
	sp(const sp& p) : obj(p.obj)
	{
		if (obj) obj->incStrong();
	}
	~sp() { if (obj) obj->decStrong(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

class Car : public RefBase
{
public:
	~Car() { cout << "~Car" << endl; }
};

int main(void)
{
	sp<Car> p1 = new Car; // 생성자
	sp<Car> p2 = p1; // 복사생성자

	return 0;
}
