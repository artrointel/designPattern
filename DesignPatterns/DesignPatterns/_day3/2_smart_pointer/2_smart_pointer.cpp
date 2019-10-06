#include<iostream>
using namespace std;
// �������̽� ����� ����ī��Ʈ ����
// ����: ��ü Ÿ�Ը� �����ϰ� ��ӹ޾ƾ� �Ѵ�.
// ����: ���� Ÿ���� ����� �� ����.(�� ��� wrapper class ���� �� ���)

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

	// T ��������� ȣ��� ������� ī��Ʈ
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
	sp<Car> p1 = new Car; // ������
	sp<Car> p2 = p1; // ���������

	return 0;
}
