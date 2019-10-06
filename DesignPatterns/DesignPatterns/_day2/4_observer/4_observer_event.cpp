
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// �޴��� ������ �� �̺�Ʈ ó�� ����� ������ ���ô�.
// 1. �������̽� ��� ������ ���� : Java, �ȵ���̵�, Ÿ����
// �޴��� ó���ϰ� ���� ��� ��� ��ü�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IMenuListener
{
	// �����ʿ� �Լ��� �ݵ�� ���ڷ� id �� �Ǵ� MenuItem* ���� �־�� �Ѵ�.
	virtual void onCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem
{
	int id;
	vector<IMenuListener*> v;
public:
	MenuItem(int n) : id(n) {}
	void addListener(IMenuListener* p) { v.push_back(p); }
	void command()
	{
		// �޴��� ���õ� ����� �ܺο� �˷��� �Ѵ�.
		// ������ ���� : �ϳ��� �̺�Ʈ�� ��ϵ� ������ü�� �����ϴ� ����
		int size = v.size();
		for (int i = 0; i < size; i++)
			v[i]->onCommand(id);
	}
};

//////////////////////////////////////////////////////////////////////////

class Camera : public IMenuListener
{
public:
	void onCommand(int id)
	{
		// �޴� id�� ���� ���ϴ� ��� ���� ! <- switch�� ���;� �ϳ׿�.
		switch (id)
		{
		case 11: break;
		case 12: break;
		}
		cout << "Camera onCommand" << endl;
	}
};

int main(void)
{
	Camera cam;
	MenuItem m1(11);
	MenuItem m2(12);
	m1.addListener(&cam);
	m2.addListener(&cam);
	m1.command();
	return 0;
}