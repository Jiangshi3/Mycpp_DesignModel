/*
工厂方法模式的优点： 之一：符合开闭原则；
            缺点：类个税增多，增加维护成本；抽象变多了也难以理解；
*/


#include <iostream>
#include <string>
using namespace std;

//抽象水果
class AbstractFruit{
public:
    virtual void showName()=0;
    virtual ~AbstractFruit();
};
class Apple : public AbstractFruit{
public:
    virtual void showName(){
        cout << "Apple" << endl;
    }
};
class Banana : public AbstractFruit{
public:
    virtual void showName(){
        cout << "Banana" << endl;
    }
};


//抽象水果工厂
class AbstractFactory{
public:
    virtual AbstractFruit* creatFruit()=0;   // 返回值是返回的抽象水果
    virtual ~AbstractFactory();
};
class AppleFactory : public AbstractFactory{
public:
    virtual AbstractFruit* creatFruit(){
        return new Apple;
    }
};
class BananaFactory : public AbstractFactory{
public:
    virtual AbstractFruit* creatFruit(){
        return new Banana;
    }
};


void test01(){
    AbstractFactory* factory = nullptr;
    AbstractFruit* fruit = nullptr;

    // 创建一个苹果工厂
    factory = new AppleFactory;
    fruit = factory->creatFruit();
    fruit->showName();
    delete fruit;
    delete factory;

    //创建一个香蕉工厂
    factory = new BananaFactory;
    fruit = factory->creatFruit();
    fruit->showName();
    delete fruit;
    delete factory;
}


int main(){
    test01();
    return 0;
}