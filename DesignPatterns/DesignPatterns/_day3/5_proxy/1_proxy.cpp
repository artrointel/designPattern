#include<iostream>
#include<conio.h>
#include"../../utils/ioacademy.h"
using namespace std;
using namespace ioacademy;

//Proxy class ; ����ϴ� Ŭ����

// Proxy Pattern : ���� ��Ҹ� ����ϴ� Ŭ����(������)
// Remote Proxy : ���ݼ���(IPC�Ǵ� ��Ʈ��ũ)�� ����ϴ� Ŭ����
// ����ڴ� IPC�� ���� ������ ���� �ȴ�.

// �ᱹ �ٸ� ���μ����� �Լ��� ȣ���ϴ� ������ �˴ϴ�. 
// RPC (Remote Procedure Call), RMI(Remote Method Invoke)

// �߰� ����: 
// �ܼ� wrapper�� �޸� ��� ������ ���� ���� ������ �����ϴ�. ������� Fly-weight�� Ȱ���� ImageProxy��
// smart pointer ���� proxy ������ �����̴�.

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

// ������ Add, Sub�Լ��� Logging �߰�

