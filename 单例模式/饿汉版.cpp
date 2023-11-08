// Eager Singleton
#include <iostream>
using namespace std;

class Singleton
{
private:
	static Singleton instance;
private:
	Singleton(){cout<<"Singleton constructor"<<endl;}
	~Singleton(){cout<<"Singleton destructor"<<endl;}
	// 如果你的类不需要支持复制构造和赋值操作，可以将下面这两个函数声明为私有，并不提供定义，以阻止外部代码使用它们。
	Singleton(const Singleton&);  
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance() {
		return instance;
	}
};

// initialize defaultly
Singleton Singleton::instance;   //这是在程序启动时分配内存并调用 构造函数 来创建对象的一种方式。不是使用 new 运算符创建对象;


/*
由于在main函数之前初始化，所以没有线程安全的问题。
但是潜在问题在于no-local static对象（函数外的static对象）在不同编译单元中的初始化顺序是未定义的。
也即，static Singleton instance;和static Singleton& getInstance()二者的初始化顺序不确定，
如果在初始化完成之前调用 getInstance() 方法会返回一个未定义的实例。
*/

void test01(){
	Singleton& obj1 = Singleton::getInstance();
	Singleton& obj2 = Singleton::getInstance();
	/*
		因为Singleton没有重载==操作符，所以不能把两个Singleton对象进行比较，只能把两个指针类型进行比较！！
		所以如果getInstance()返回的是引用，则只能 if (&obj1 == &obj2) 比较
		如果getInstance()返回的是指针类型，Singleton* obj1 = Singleton::getInstance();，则只能 if (obj1 == obj2) 比较。
	*/
	
    if (&obj1 == &obj2) {
        std::cout << "obj1 和 obj2 是同一个对象======" << std::endl;
    } else {
        std::cout << "obj1 和 obj2 不是同一个对象" << std::endl;
    }
}

int main(){
	test01();
	return 0;
}


