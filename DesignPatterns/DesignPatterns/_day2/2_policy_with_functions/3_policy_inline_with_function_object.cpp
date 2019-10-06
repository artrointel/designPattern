// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����.(�׷��� �����Ϸ��� ��� ���̵� �� �� �����Ƿ� �Ϲ� �Լ��� �ζ��� ġȯ�� �� ����.)
//		signature�� ������ �Լ��� ��� ���� Ÿ���̴�.

// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//		signature�� �����ص� ��� �Լ���ü�� �ٸ� Ÿ���̴�.

struct Less
{
	bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	bool operator()(int a, int b) { return a > b; }
};


// ��å ��ü�� �����ϰ� ��å�� �ζ��� ġȯ�Ǵ� �Լ�
// template + �Լ� ��ü�� ����� ��� !
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

