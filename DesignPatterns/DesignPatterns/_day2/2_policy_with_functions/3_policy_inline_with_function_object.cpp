// 1. 일반 함수는 자신만의 타입이 없다.(그래서 컴파일러는 어느 것이든 올 수 있으므로 일반 함수를 인라인 치환할 수 없다.)
//		signature가 동일한 함수는 모두 같은 타입이다.

// 2. 함수 객체는 자신만의 타입이 있다.
//		signature가 동일해도 모든 함수객체는 다른 타입이다.

struct Less
{
	bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	bool operator()(int a, int b) { return a > b; }
};


// 정책 교체가 가능하고 정책이 인라인 치환되는 함수
// template + 함수 객체로 만드는 기술 !
template<typename T>
void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))
			{
				swap(x[i], x[j]);
			}
		}
	}
}

int main(void)
{
	int x[] = { 2, 4, 6, 8, 1, 3, 5 ,7 };
	Less f1;
	Greater f2;
	Sort(x, 10, f1);
}

