/*
懒汉模式；
单例实例在第一次被使用时才进行初始化，这叫做延迟初始化。
单线程下是安全的；多线程下Lazy Singleton存在内存泄露的问题;
*/

#include <iostream>
using namespace std;

class singleton{
private:
    singleton(){}  //构造函数是私有的
    ~singleton(){}
    singleton(const singleton&);
    singleton& operator=(const singleton&);

    static singleton* instance;
public:
    static singleton* getinstance();  //供用户获取单例的全局访问点
};

singleton* singleton::instance = nullptr;  //私有静态成员的定义；类外初始化
singleton* singleton::getinstance(){
    if(instance==nullptr){           //如果多个线程同时到达，会创建new，造成内存泄漏；
        instance=new singleton();
    }
    return instance;
}


void test01(){
    singleton* obj1 = singleton::getinstance();
    singleton* obj2 = singleton::getinstance();
    //只能进行两个指针的比较。因为singleton没有重载operator==  
    if(obj1 == obj2){
        cout << " == " << endl;
    }else{
        cout << " != " << endl;
    }
}

int main(){
	test01();
	return 0;
}


