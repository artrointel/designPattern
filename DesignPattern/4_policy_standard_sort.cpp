

#include<iostream>
#include<algorithm> // 이미 이 안에 sort()가 있습니다.
using namespace std;

bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

struct Less
{
	bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	bool operator()(int a, int b) { return a > b; }
};


int main(void)
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 1. 비교 정책으로 일반함수를 사용할 때
	// 장점 : sort의 기계어 코드가 하나이다. 정책을 여러 번 교체해도 sort()의 기계어는 한개이다.
	//			코드메모리 사용량 감소.
	// 단점 : 정책이 인라인 치환이 될 수 없다.
	sort(x, x + 10, cmp1);	// sort(int*, int*, bool(*)(int,int)) 인 함수 생성
	sort(x, x + 10, cmp2);	// sort(int*, int*, bool(*)(int,int)) 인 함수 생성

	// 2. 비교 정책으로 함수객체를 사용할 떄
	// 장점 : 정책이 인라인 치환된다. 성능 향상
	// 단점 : 정책을 교체한 횟수만큼 sort() 기계어 생성, 코드메모리 증가.
	Less f1;
	Greater f2;
	sort(x, x + 10, f1);		// sort(int*,int*,Less) 함수생성
	sort(x, x + 10, f2);		// sort(int*,int*,Greater) 함수생성
	return 0;
}



