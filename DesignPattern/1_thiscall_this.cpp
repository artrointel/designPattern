// 1_thiscall.cpp
#include <iostream>
using namespace std;
// 1. 일반 멤버 함수는 1번째 인자로 this가 추가된다.!
// 2. static 멤버 함수는 this가 추가되지 않는다.!
class Point
{
	int x, y;
public:
	void set(int a, int b) // set(Point* const this , int a, int b)
	{					  // {
		x = a;			  //		this->x = a;
		y = b;			  //		this->y = b;
	}					  // }

	static void foo(int a) // void foo( int a )
	{
		x = a;		// this->x = a  가 되야 합니다.
	}				// 그런데 this가 없습니다.
};					// 그래서 static 멤버함수에서는
					// 일반 멤버data에 접근할수 없다!!
int main()
{
	Point::foo(10); // static 멤버 함수는 객체가 없어도
					// 호출가능합니다.
					// foo(10); 인자로 추가할 객체가 없습니다!

	Point p1, p2;
	p1.set(10, 20); // 이 한줄의 정확한 원리는 뭘까요 ?
					// set(&p1, 10, 20) 으로 컴파일 됩니다.
					// push	20
					// push 10  진짜 인자는 스택에 넣고
					// mov  ecx, &p1  객체 주소는 레지스터에
					// call set..  함수 호출...
}