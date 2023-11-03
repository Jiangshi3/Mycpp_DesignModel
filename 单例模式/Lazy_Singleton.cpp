/*
懒汉模式；
单例实例在第一次被使用时才进行初始化，这叫做延迟初始化。
单线程下是安全的；多线程下Lazy Singleton存在内存泄露的问题;
*/

#include <iostream>

class singleton{
private:
    singleton(){}  //构造函数是私有的
    ~singleton(){}
    singleton(const singleton&){}
    singleton& operator=(const singleton&){}

    static singleton* instance;
public:
    static singleton* getinstance();  //供用户获取单例的全局访问点
};

singleton* instance=nullptr;
singleton* singleton::getinstance(){
    if(instance==nullptr){           //如果多个线程同时到达，会创建new，造成内存泄漏；
        instance=new singleton();
    }
    return instance;
}


