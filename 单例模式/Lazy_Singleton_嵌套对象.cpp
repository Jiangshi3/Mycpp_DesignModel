// 这两个懒汉模式都不是线程安全的。

#include <iostream>

class Singleton
{
private:
	static Singleton* instance;
private:
	Singleton() { };
	~Singleton() { };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
    // 实现一个内嵌垃圾回收类
	class Deletor {
	public:
		~Deletor() {
			if(Singleton::instance != NULL)
				delete Singleton::instance;
		}
	};
	static Deletor deletor;
public:
	static Singleton* getInstance() {
		if(instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = nullptr;
Singleton::Deletor deletor;



/*
在程序运行结束时，系统会调用静态成员deletor的析构函数，该析构函数会删除单例的唯一实例。使用这种方法释放单例对象有以下特征：

在单例类内部定义专有的嵌套类。
在单例类内定义私有的专门用于释放的静态成员。
利用程序在结束时析构全局变量的特性，选择最终的释放时机。
在单例类内再定义一个嵌套类，总是感觉很麻烦。
*/



