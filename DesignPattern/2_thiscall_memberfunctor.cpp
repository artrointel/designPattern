// 1_thiscall2

// 1. 일반 함수포인터에 멤버 함수의 주소를 담을수없다.(this문제)

// 2. 일반 함수포인터에 static 멤버 함수 주소는 담을수 있다.
//		=> this가 추가되지 않으므로!

// 3. 멤버 함수의 포인터를 만들고 사용하는 방법.
//     => 아래 main 함수 참고..

// ** 다른 객체

class Dialog
{
public:
	void Close() {}
};

int main()
{
	// 멤버 함수의 주소를 담는 방법
	void(Dialog::*f3)() = &Dialog::Close;
	//f3(); // 될까요 ? error. this가 없다.

	Dialog dlg;
	//	dlg.f3(); // error. dlg에서 f3이라는 멤버를 찾게된다.
	//	dlg.*f3(); // .* 가 ()보다 우선순위가 낮다. 우선순위를
	// 올려야 한다.

	(dlg.*f3)(); // ok.. 결국 dlg.Close()

				 //	void(*f1)() = &foo; // ok!!
				 //	void(*f2)() = &Dialog::Close; // 될까요 ? 잘생각해보세요
				 // 왜 안될까요 ?
}