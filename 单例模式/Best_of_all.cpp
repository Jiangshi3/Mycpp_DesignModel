/*
C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了内部静态变量的线程安全性。
在C++11标准下，《Effective C++》提出了一种更优雅的单例模式实现，使用函数内的 local static 对象。
这样，只有当第一次访问getInstance()方法时才创建实例。这种方法也被称为Meyers' Singleton.
*/

class Singleton
{
private:
	Singleton() { };
	~Singleton() { };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance() 
        {
		static Singleton instance;
		return instance;
	}
};

/*
singleton *singleton::instance() {
    static singleton p;
    return &p;
}
单线程下，正确。
C++11及以后的版本（如C++14）的多线程下，正确。
C++11之前的多线程下，不一定正确。
原因在于在C++11之前的标准中并没有规定local static变量的内存模型。于是乎它就是不是线程安全的了。
但是在C++11却是线程安全的，这是因为新的C++标准规定了当一个线程正在初始化一个变量的时候，其他线程必须得等到该初始化完成以后才能访问它。

*/

