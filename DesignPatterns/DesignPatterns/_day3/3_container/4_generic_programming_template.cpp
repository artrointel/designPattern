#include<iostream>
using namespace std;

// �Ʒ�ó�� ����� 2���� ������ �ֽ��ϴ�.
//		1. ������ Ÿ�԰� ã�� ����� Ÿ���� �����˴ϴ�.
//			double �迭���� int�� ã�� �� �����ϴ�.
//		2. T*��� �ϸ� �ݵ�� �����͸� ����ؾ� �մϴ�.
//			����Ʈ�����͸� ����� �� �����ϴ�. (����Ʈ�����ʹ� ���������� �ƴ� ��ü�̱� ����)
// template<typename T>
// T* xfind(T* first, T* last, T value) // (body ������ ����)

// �ᱹ �Ʒ�ó�� ������ �մϴ�.
// �Ʒ� �Լ��� [fist, last) ������ ��� Ÿ���� �迭���� �����˻� ����
// ã�� ���� ��� last�� ����
// �Ʒ� �Լ��� C++ ǥ��(STL) find()�Լ��� �����մϴ�.
template<typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first; // ã������ first�� 0�� ��� ȥ��
}

int main(void)
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = xfind(x, x + 10, 3);
	
	if (p == x + 10)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;

	return 0;
}