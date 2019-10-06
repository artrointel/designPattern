#include<iostream>
using namespace std;

// ���� : ������ ��ü�� �ٸ� Ÿ���� ������ó�� ���Ǵ� ��
// ���� : ->, *�����ڸ� �������ؼ� ������ó�� ���̰� �Ѵ�.
// ���� : ��¥ �����Ͱ� �ƴ϶� ��ü�̴�.
//			����/����/����/�Ҹ��� ��� ������ ����ڰ� ������ �� �ִ�.
//			��ǥ�� Ȱ���� �Ҹ��ڿ����� �ڵ����� ���
// �Ʒ� Ŭ������ �ٽ��Դϴ�.

class Car
{
public:
	void Go() { cout << "Car go" << endl; }
	~Car() { cout << "Car �ı�" << endl; }
};

template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; }
	T* operator->() { return obj; } // �Լ� ���� ���°� return obj;�� ������ �Ʒ��� ����
	T& operator*() { return *obj; } // ����. ���������� �ƴϸ� ������ �߸��� ��
};

int main(void)
{
	Ptr<Car> p = new Car;	// Ptr p(new Car)�� �����ϼ���.
	p->Go();				// (p.operator->())Go(); �� ���������
							// (p.operator->())->Go(); �� �ؼ��˴ϴ�.
	(*p).Go();
	return 0;
}