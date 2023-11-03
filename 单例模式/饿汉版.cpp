// Eager Singleton
class Singleton
{
private:
	static Singleton instance;
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance() {
		return instance;
	}
};

// initialize defaultly
Singleton Singleton::instance;


/*
由于在main函数之前初始化，所以没有线程安全的问题。
但是潜在问题在于no-local static对象（函数外的static对象）在不同编译单元中的初始化顺序是未定义的。
也即，static Singleton instance;和static Singleton& getInstance()二者的初始化顺序不确定，
如果在初始化完成之前调用 getInstance() 方法会返回一个未定义的实例。
*/

