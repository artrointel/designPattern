#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Composite 패턴 !!

// 복합 객체는 개별 객체 뿐 아니라 복합 객체 자신도 보관한다. (Folder has Folder, File)
// 복합객체와 개별객체는 동일한 부모가 있어야 한다. (Folder has Folder, File as Item)
// 복합객체와 개별객체의 사용법이 동일하다. (ex. getSize)
// 사용법은 부모에 있어야 한다. => command는 부모에 있어야 한다. (ex. getSize)
// 재귀적 포함을 사용하는 디자인 패턴 (Folder has Folder, File)

class Item
{
protected:
	string name;
public:
	Item() {}
	Item(string s) : name(s) {}

	string getName() { return name; }
	virtual int getSize() = 0;
};

class File : public Item
{
	int size;
public:
	File(string s, int n)
		: Item(s), size(n) {}

	virtual int getSize()
	{
		return size;
	}
};

class Folder : public Item
{
protected:
	vector<Item*> v;
public:
	Folder(string s)
		: Item(s) {}

	virtual int getSize()
	{
		int size = 0;
		for (int i = 0; i < v.size(); i++)
			size += v[i]->getSize();
		return size;
	}

	void addItem(Item* p)
	{
		v.push_back(p);
	}

	// TODO deleteItem, virtual 소멸자 등
};

int main(void)
{
	Folder* root = new Folder("root");
	Folder* fo1 = new Folder("A");
	Folder* fo2 = new Folder("B");

	// 화일은 자신만의 크기가 있습니다.
	File* f1 = new File("a.text", 10);
	File* f2 = new File("b.text", 20);
	File* f3 = new File("c.text", 30);

	root->addItem(fo1);
	fo1->addItem(fo2);
	fo2->addItem(f3);
	fo1->addItem(f2);
	root->addItem(f1);

	// 폴더는 자신의 크기는 없지만 크기를 구할수 있습니다.
	cout << f1->getSize() << endl;	// 10
	cout << fo1->getSize() << endl;	// 50
	cout << root->getSize() << endl;// 60

	return 0;
}