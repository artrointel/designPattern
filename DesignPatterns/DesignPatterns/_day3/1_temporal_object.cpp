#include<iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p = { 1, 2 };


// Point foo()	// 값 리턴 : 임시객체가 생성된다.
Point foo()	// 참조 리턴 : 리턴용 임시객체를 만들지 말라는 의도, 지역객체를 리턴하기위해 반드시 필요
{
	return p; // 값을 반환할 때 리턴을 위해 복사생성자를 이용해 임시객체를 생성한다.
}

Point& goo()	// 참조 리턴 : 리턴용 임시객체를 만들지 말라는 의도, 지역객체를 리턴하기위해 반드시 필요
{
	return p; // 값을 반환할 때 리턴을 위해 복사생성자를 이용해 임시객체를 생성한다.
}

int main()
{
	cout << "ff";
	foo().x = 10; // 임시객체 리턴, 리턴과 동시에 파괴(소멸자 호출)
	cout << p.x << endl;

	goo().x = 10;
	cout << p.x << endl;
}