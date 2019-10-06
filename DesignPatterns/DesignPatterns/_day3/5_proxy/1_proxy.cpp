#include<iostream>
#include<conio.h>
#include"../../utils/ioacademy.h"
using namespace std;
using namespace ioacademy;

//Proxy class ; 대신하는 클래스

// Proxy Pattern : 기존 요소를 대신하는 클래스(대행자)
// Remote Proxy : 원격서버(IPC또는 네트워크)를 대신하는 클래스
// 사용자는 IPC에 대한 개념을 몰라도 된다.

// 결국 다른 프로세스의 함수를 호출하는 개념이 됩니다. 
// RPC (Remote Procedure Call), RMI(Remote Method Invoke)

// 추가 설명: 
// 단순 wrapper와 달리 기능 수행을 위한 별도 연산이 가능하다. 예를들어 Fly-weight을 활용한 ImageProxy나
// smart pointer 또한 proxy 패턴의 일종이다.

class Calc
{
	int server;
public:
	Calc() { server = IoFindServer("Calc"); }
	int Add() (int a, int b) { return IoSendServer(server, 1, a, b); }
	int Sub() (int a, int b) { return IoSendServer(server, 2, a, b); }
};

int main(void)
{
	Calc* pCalc = new Calc;
	_getch(); cout << pCalc->Add(1, 2) << endl;
	_getch(); cout << pCalc->Sub(1, 2) << endl;
}

// 서버의 Add, Sub함수에 Logging 추가

