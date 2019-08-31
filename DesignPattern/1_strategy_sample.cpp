
// 동기화 전략은 다른 클래스 만들때도 필요하다.
// 정책의 재사용을 위한 동기화 정책을 담은 정책 클래스를 설계한다.
// 인터페이스 기반 정책 변경
// 장점 : 정책을 다른 클래스에서도 사용가능
//        실행시간 정책교체가능

// 단점 : 가상함수기반 이므로 느리다.!
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

List<int> st; // 전역변수. 멀티스레드에 안전하지 않다.

int main()
{
	st.push_front(10);
}
