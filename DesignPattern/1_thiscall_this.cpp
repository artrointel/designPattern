// 1_thiscall.cpp
#include <iostream>
using namespace std;
// 1. �Ϲ� ��� �Լ��� 1��° ���ڷ� this�� �߰��ȴ�.!
// 2. static ��� �Լ��� this�� �߰����� �ʴ´�.!
class Point
{
	int x, y;
public:
	void set(int a, int b) // set(Point* const this , int a, int b)
	{					  // {
		x = a;			  //		this->x = a;
		y = b;			  //		this->y = b;
	}					  // }

	static void foo(int a) // void foo( int a )
	{
		x = a;		// this->x = a  �� �Ǿ� �մϴ�.
	}				// �׷��� this�� �����ϴ�.
};					// �׷��� static ����Լ�������
					// �Ϲ� ���data�� �����Ҽ� ����!!
int main()
{
	Point::foo(10); // static ��� �Լ��� ��ü�� ���
					// ȣ�Ⱑ���մϴ�.
					// foo(10); ���ڷ� �߰��� ��ü�� �����ϴ�!

	Point p1, p2;
	p1.set(10, 20); // �� ������ ��Ȯ�� ������ ����� ?
					// set(&p1, 10, 20) ���� ������ �˴ϴ�.
					// push	20
					// push 10  ��¥ ���ڴ� ���ÿ� �ְ�
					// mov  ecx, &p1  ��ü �ּҴ� �������Ϳ�
					// call set..  �Լ� ȣ��...
}