#include<iostream>
using namespace std;

// 개념 : 임의의 객체가 다른 타입의 포인터처럼 사용되는 것
// 원리 : ->, *연산자를 재정의해서 포인터처럼 보이게 한다.
// 장점 : 진짜 포인터가 아니라 객체이다.
//			생성/복사/대입/소멸의 모든 과정을 사용자가 제어할 수 있다.
//			대표적 활용은 소멸자에서의 자동삭제 기능
// 아래 클래스가 핵심입니다.

class Car
{
public:
	void Go() { cout << "Car go" << endl; }
	~Car() { cout << "Car 파괴" << endl; }
};

template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; }
	T* operator->() { return obj; } // 함수 구현 형태가 return obj;인 이유는 아래를 참조
	T& operator*() { return *obj; } // 주의. 참조리턴이 아니면 완전히 잘못된 것
};

int main(void)
{
	Ptr<Car> p = new Car;	// Ptr p(new Car)로 생각하세요.
	p->Go();				// (p.operator->())Go(); 의 모양이지만
							// (p.operator->())->Go(); 로 해석됩니다.
	(*p).Go();
	return 0;
}