#include<iostream>

using namespace std;

// template���� Collection(List, Stack��) �� ���� ��
// ���ſ� ������ ���ÿ� �ϴ� �Լ��� ������ ���� ����
// 
// 1. ���������� ���ؼ� �ӽð�ü�� �����Ϸ���..
// 2. ���� �������� ���� ������ �����ϱ� ���� - �ݿ��ϳ�!

template<typename T>
class Stack
{
	T buff[10];
	int index;
public:
	Stack() : index(-1) {}
	// void push(T a) {buff[index++] = a;}
	// -> ����ü ���� ������(call by value) ������ ���� ���ϰ� �ִ�.
	// ������ �޴°� ����.
	void push(const T& a) { buff[++index] = a; }
	//T	pop() {return buff[--index]; } // �����δ� ���ŵ� ���� �����ϸ� �ȵǹǷ� �ٸ��� ����(���� ���ÿ��� ������)
	// pop()�� ���ſ� ������ ���ÿ� �ϸ� �ӽð�ü�� ������ ���� �� ����. �� ����ȭ�� �� ����.
	// ���ſ� ������ �и�����.
	void pop() { --index; } // ���Ÿ�
	T& top() { return buff[index]; } // ���ϸ�
	// �����Ͱ� ���ŵ��� �����Ƿ� ���������� �����ϴ�.
};

int main(void)
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	return 0;
}