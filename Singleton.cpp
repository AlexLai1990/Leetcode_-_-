class Lock{
public:
	Lock(){}
	~Lock(){}
	void AcquireLock();
	void ReleaseLock();
};

template <typename T>
class Singleton{
private:
	static T* obj;
	static Lock lock;
	// or we can use a local static mutex as lock
	// static std::mutex ioLock;
public:
	static T* GetInstatnce();
protected:
	// the class is used for special purpose
	Singleton() {}
};

template <typename T>
T* Singleton<T>::obj = NULL;

template <typename T>
Lock Singleton<T>::lock;

template <typename T>
T* Singleton<T>::GetInstatnce(){
	if (obj == NULL) {
		lock.AcquireLock();
		// using lock_guard will auto deallocate when it is out of scope.
		// std::lock_guard<std::mutex> l(ioLock);
		if (obj == NULL) {
			obj = new T;
		}
		lock.ReleaseLock();
	}
	return obj;
}	

class Resturant{

};
// each time we use Singeton class to get the instance,
// but only one instance has been created in the Singeton class
int main() {
	Resturant *m_rest = Singeton<Resturant>::GetInstatnce();
	return 1;
}
