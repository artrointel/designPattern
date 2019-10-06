// 4_함수바인딩
#include <iostream>
using namespace std;

class Animal
{
public:	void Cry() { cout << "Animal Cry" << endl; } // 1
};
class Dog : public Animal
{
	// override : 부모의 함수를 자식이 재정의하는것.
public:	void Cry() { cout << "Dog Cry" << endl; } // 2
};

int main()
{
	Animal a; a.Cry(); // 1
	Dog    d; d.Cry(); // 2

	Animal* p = 0;
	p = &d; // 부모 포인터로 자식을 가리키는것 => Upcasting
			//---------------------------------
	int n;
	cin >> n;

	if (n == 0) p = &a;
	//-------------------------
	// 컴파일 시간에 p가 누구를 가르키는지 알수 있을까 ?
	p->Cry(); // 1 ? 2
}
// p->Cry() 를 어느 함수로 연결할것인가 ? => 함수바인딩

// 1. static binding : 컴파일 시간에 어느 함수를 호출할지를
//				결정하는것. 원리는 포인터 타입으로 함수를결정
//				Animal Cry 호출
// = early binding 실행속도가 빠르다. 비 논리적
//		C++, C#


// 2. dynamic binding : 컴파일 시간에 p의 메모리를 조사하는
//				기계어 코드 생성후 실행할때 메모리를 조사해서
//				호출. Dog Cry 호출
//	= late binding. 느리다. 논리적.
//     java, Objective-C, 
//		C++과 C#의 virtual function






