
// ����ȭ ������ �ٸ� Ŭ���� ���鶧�� �ʿ��ϴ�.
// ��å�� ������ ���� ����ȭ ��å�� ���� ��å Ŭ������ �����Ѵ�.
// �������̽� ��� ��å ����
// ���� : ��å�� �ٸ� Ŭ���������� ��밡��
//        ����ð� ��å��ü����

// ���� : �����Լ���� �̹Ƿ� ������.!
struct ISync
{
	virtual void Lock() = 0;
	virtual void Unlock() = 0;
	virtual ~ISync() {}
};
template<typename T> class List
{
	ISync* pSync;
public:
	List() : pSync(0) {}

	void setSyncPolicy(ISync* p) { pSync = p; }

	void push_front(const T& a)
	{
		pSync->Lock();
		//......
		pSync->Unlock();
	}
};

List<int> st; // ��������. ��Ƽ�����忡 �������� �ʴ�.

int main()
{
	st.push_front(10);
}
