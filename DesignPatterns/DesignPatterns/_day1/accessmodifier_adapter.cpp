// 3_���ٺ�����2
#include <iostream>
using namespace std;

// �� private ����� ����ϴ°� ? 

// �θ�� ���� ������ ���� ������(�ڽ��� �θ� �Լ��� ���������)
// �������̽��� ���� ������ �ʰڴ�.( �θ� �Լ��� �ܺ� ����
//								������ �ʰڴٴ°�)


// list�� �̹� �ֽ��ϴ�.
#include <list>

// �׷��� stack�� �ʿ��մϴ�.
// 1. stack�� �ٽ� ������
// 2. list�� �������θ� ����ϸ� stackó�� ���δ�. list��
//    ��������.

// Adapter ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ�
//				 Ŭ���̾�Ʈ�� �䱸�ϴ� ���ο� Ŭ������
//				 �����ϴ� ��!
// �Ʒ� ó�� ����� �޸𸮻�뷮������ ������ ���ϰ� ��������
// ���ο� Ŭ������ �����Ҽ��� �ְ� �ȴ�.
/*
template<typename T> class stack : private list<T> // private ���
{
public:
inline void push( const T& a ) { list<T>::push_back(a); }
inline T&   top()              { return list<T>::back(); }
inline void pop()              { list<T>::pop_back(); }
};
*/
// Java ����� ��Ӱ����ΰ�� list Ŭ������ �������̽��� ����Ǵ� ������ �߻��Ѵ�.

// S/W�� ������ ��Ӱ� ������ �ִ�. - ������ �������� ������

#include <vector>
#include <deque>  // list�� vector�� ����..
// ���ӵ� �޸𸮸� �ٽ� list��
template<typename T, typename C = deque<T>> class stack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline T&   top() { return st.back(); }
	inline void pop() { st.pop_back(); }
};

#include <stack> // C++ ǥ���� STL�� stack Ŭ����
// ���� "stack adapter" ��� �θ��ϴ�.
// ������ ���� �����մϴ�.
int main()
{
	stack<int, list<int>> s1;
	stack<int, vector<int>> s2;

	stack<int> s;
	s.push(10);
	s.push(20);
	// s.push_front(30); // (�߸��� ��� ���ɼ� -> private ���)
}



