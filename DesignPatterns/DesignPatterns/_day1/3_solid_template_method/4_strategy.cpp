// 8_LineEdit - 중요한 예제입니다.
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 변하는 것을 분리하는 두번째 방법
// 변하는 것을 다른 클래스로, 변해야 하므로 교체 가능해야 한다.
// 인터페이스 기반 설계

struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
	virtual ~IValidator() {}
};

// 주민 번호 : 881  1    확인

class LineEdit
{
	string data;

	//--------------
	IValidator* pVal;
public:
	LineEdit() : pVal(0) {}

	void setValidator(IValidator* p) { pVal = p; }
	//-------------------------------------------------

	string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch();

			if (c == 13 && (pVal == 0 || pVal->iscomplete(data))) break; // enter
			if (pVal == 0 || pVal->validate(data, c))
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// 값의 유효성을 확인하는 다양한 validator를 제공한다.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(string s, char c)
	{
		return s.size() < value && isdigit(c);
	}
	virtual bool iscomplete(string s)
	{
		return s.size() == value;
	}
};
int main()
{
	LineEdit edit;

	LimitDigitValidator v(5);
	edit.setValidator(&v);

	LimitDigitValidator v2(15);
	edit.setValidator(&v2);

	while (1)
	{
		string s = edit.getData();
		cout << s << endl;
	}
}