#include<iostream>
#include<algorithm>
using namespace std;

// ���̺귯�� �����ڸ� ������ ���ô�.
// 1. ���� - ����� �Ѵ�.
// 2. ������ - ��å ������ �����ؾ� �Ѵ�.
// C��Ÿ���� �Ϲ��Լ����� ���ؾ� �ϴ� ��(��å, ������)�� �Լ� ���ڷ� �̾Ƴ���.
// ��κ� �Լ� ������ !
// Cǥ���� qsort()�� �Ʒ� �Լ��� �����ϰ� ������ �Ǿ��ֽ��ϴ�.
void Sort(int* x, int n, bool(*comp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//if(x[i]>x[j])
			if (comp(x[i], x[j]))
			{
				swap(x[i], x[j]);
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
// Sort()���� ����� �� ��å�Լ�
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }
// ���Լ� ��å�� �������̹Ƿ� ������. runtime ��ü �����ϹǷ� inline ġȯ�� �ȵȴ�.

int main(void)
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int length = sizeof(x) / sizeof(*x);
	Sort(x, length, cmp1);

	for (int i = 0; i < length; i++)
		cout << x[i] << endl;

	return 0;
}
