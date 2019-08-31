#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Composite ���� !!

// ���� ��ü�� ���� ��ü �� �ƴ϶� ���� ��ü �ڽŵ� �����Ѵ�. (Folder has Folder, File)
// ���հ�ü�� ������ü�� ������ �θ� �־�� �Ѵ�. (Folder has Folder, File as Item)
// ���հ�ü�� ������ü�� ������ �����ϴ�. (ex. getSize)
// ������ �θ� �־�� �Ѵ�. => command�� �θ� �־�� �Ѵ�. (ex. getSize)
// ����� ������ ����ϴ� ������ ���� (Folder has Folder, File)

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

	// TODO deleteItem, virtual �Ҹ��� ��
};

int main(void)
{
	Folder* root = new Folder("root");
	Folder* fo1 = new Folder("A");
	Folder* fo2 = new Folder("B");

	// ȭ���� �ڽŸ��� ũ�Ⱑ �ֽ��ϴ�.
	File* f1 = new File("a.text", 10);
	File* f2 = new File("b.text", 20);
	File* f3 = new File("c.text", 30);

	root->addItem(fo1);
	fo1->addItem(fo2);
	fo2->addItem(f3);
	fo1->addItem(f2);
	root->addItem(f1);

	// ������ �ڽ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	cout << f1->getSize() << endl;	// 10
	cout << fo1->getSize() << endl;	// 50
	cout << root->getSize() << endl;// 60

	return 0;
}