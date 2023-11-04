/*
抽象工厂模式；
virtual ~AbstractFactory() {} 是一个虚析构函数的定义（definition），它包含了函数体，也就是析构函数的实际实现。
virtual ~AbstractFactory(); 是一个虚析构函数的声明（declaration），它仅用于告诉编译器这个类中有一个虚析构函数，但没有提供函数体的实现。实际的函数体实现可以在类的定义之外的地方提供。

*/


#include <iostream>
using namespace std;

//抽象苹果工厂
class AbstractApple{
public:
    virtual void showName() = 0;
    // virtual ~AbstractApple(){}   // 虚析构函数的定义式
    virtual ~AbstractApple();       // 虚析构函数的声明式； 可以在类外实现
};
AbstractApple::~AbstractApple(){}   // 虚析构函数的实现
//China苹果
class ChinaApple : public AbstractApple{
public:
    virtual void showName(){
        cout << "ChinaApple" << endl;
    }
};
//US苹果
class USApple : public AbstractApple{
public:
    virtual void showName(){
        cout << "USApple" << endl;
    }
};

/*--------------------------------------------*/
//抽象香蕉工厂
class AbstractBanana{
public:
    virtual void showName() = 0;
    virtual ~AbstractBanana(){}
};
//China香蕉
class ChinaBanana : public AbstractBanana{
public:
    virtual void showName(){
        cout << "ChinaBanana" << endl;
    }
};
//US香蕉
class USBanana : public AbstractBanana{
public:
    virtual void showName(){
        cout << "USBanana" << endl;
    }
};

/*--------------------------------------------*/
//抽象工厂  --针对产品族
class AbstractFactory{
public:
    virtual AbstractApple* createApple() = 0;
    virtual AbstractBanana* createBanana() = 0;
    virtual ~AbstractFactory(){}   //虚析构函数的定义式
};
//China工厂
class ChinaFactory : public AbstractFactory{
public:
    virtual AbstractApple* createApple(){
        return new ChinaApple;
    }
    virtual AbstractBanana* createBanana(){
        return new ChinaBanana;
    }
};
//US工厂
class USFactory : public AbstractFactory{
public:
    virtual AbstractApple* createApple(){
        return new USApple;
    }
    virtual AbstractBanana* createBanana(){
        return new USBanana;
    }
};


void test01(){
    AbstractFactory* factory = nullptr;
    AbstractApple* apple = nullptr;
    AbstractBanana* banana = nullptr;

    //China工厂
    factory = new ChinaFactory;
    apple = factory->createApple();
    banana = factory->createBanana();
    apple->showName();
    banana->showName();
    delete apple;
    delete banana;
    delete factory;

    //US工厂
    factory = new USFactory;
    apple = factory->createApple();
    apple->showName();
    delete apple;
    delete factory;
}


int main(){
    test01();
    return 0;
}