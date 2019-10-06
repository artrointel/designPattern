

#include<iostream>
#include<algorithm> // �̹� �� �ȿ� sort()�� �ֽ��ϴ�.
using namespace std;

bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

struct Less
{
	bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	bool operator()(int a, int b) { return a > b; }
};


int main(void)
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 1. �� ��å���� �Ϲ��Լ��� ����� ��
	// ���� : sort�� ���� �ڵ尡 �ϳ��̴�. ��å�� ���� �� ��ü�ص� sort()�� ����� �Ѱ��̴�.
	//			�ڵ�޸� ��뷮 ����.
	// ���� : ��å�� �ζ��� ġȯ�� �� �� ����.
	sort(x, x + 10, cmp1);	// sort(int*, int*, bool(*)(int,int)) �� �Լ� ����
	sort(x, x + 10, cmp2);	// sort(int*, int*, bool(*)(int,int)) �� �Լ� ����

	// 2. �� ��å���� �Լ���ü�� ����� ��
	// ���� : ��å�� �ζ��� ġȯ�ȴ�. ���� ���
	// ���� : ��å�� ��ü�� Ƚ����ŭ sort() ���� ����, �ڵ�޸� ����.
	Less f1;
	Greater f2;
	sort(x, x + 10, f1);		// sort(int*,int*,Less) �Լ�����
	sort(x, x + 10, f2);		// sort(int*,int*,Greater) �Լ�����
	return 0;
}



