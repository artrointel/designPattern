// 8_LineEdit - �߿��� �����Դϴ�.
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// ���ϴ� ���� �и��ϴ� �ι�° ���
// ���ϴ� ���� �ٸ� Ŭ������, ���ؾ� �ϹǷ� ��ü �����ؾ� �Ѵ�.
// �������̽� ��� ����

struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
	virtual ~IValidator() {}
};

// �ֹ� ��ȣ : 881  1    Ȯ��

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

// ���� ��ȿ���� Ȯ���ϴ� �پ��� validator�� �����Ѵ�.
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