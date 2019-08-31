// 9_��������3
#include <iostream>
using namespace std;

// template ����� ��å Ŭ���� ��ü
// ���� : ��å �Լ��� �ζ��� �̹Ƿ� �������ϰ� ����.
// ���� : ����ð� ��å ��ü�� �Ұ����ϴ�.

// Policy Base(���� ���� �����α��)
// ���� : "Modern C++ Design" å ����.

template<typename T, typename ThreadModel = NoLock>
class List : public ThreadModel
{
public:
	void push_front(const T& a)
	{
		Lock();
		//......
		Unlock();
	}
};
// ����ȭ ��å�� ���� ��å Ŭ������ �����Ѵ�.
// ��Ģ : ��� ����ȭ ��å���� Lock()/Unlock()�� �־���Ѵ�.
class NoLock
{
public:
	inline void Lock() {}
	inline void Unlock() {}
};
class MutexLock
{
public:
	inline void Lock() { cout << "Mutex Lock" << endl; }
	inline void Unlock() { cout << "Mutex Unlock" << endl; }
};
//---------------------------------------------
List<int, NoLock> s1;
List<int, MutexLock> s2;

List<int> st; // ��������. ��Ƽ�����忡 �������� �ʴ�.

int main()
{
	st.push_front(10);
}
