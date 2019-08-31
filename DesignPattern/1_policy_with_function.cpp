#include<iostream>
#include<algorithm>
using namespace std;

// 라이브러리 설계자를 생각해 봅시다.
// 1. 성능 - 빨라야 한다.
// 2. 유연성 - 정책 변경이 가능해야 한다.
// C스타일의 일반함수에서 변해야 하는 것(정책, 가변성)은 함수 인자로 뽑아낸다.
// 대부분 함수 포인터 !
// C표준의 qsort()가 아래 함수와 동일하게 디자인 되어있습니다.
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
// Sort()에서 사용할 비교 정책함수
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }
// 비교함수 정책은 포인터이므로 느리다. runtime 교체 가능하므로 inline 치환도 안된다.

int main(void)
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int length = sizeof(x) / sizeof(*x);
	Sort(x, length, cmp1);

	for (int i = 0; i < length; i++)
		cout << x[i] << endl;

	return 0;
}
