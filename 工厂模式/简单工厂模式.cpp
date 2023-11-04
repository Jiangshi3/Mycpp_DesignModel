/*
简单工厂不属于23个设计模式；
    缺点：1、增加新的功能是通过修改源代码实现，不符合开闭原则；(Factory这个类不符合)
          2、Factory这个类职责过重，发生问题，会影响很多使用这个工厂的模块； 不符合单一职责原则
    解决：把这个工厂抽象出去，每个类对应一个工程--->工厂方法模式。
*/


#include <iostream>
#include <string>
using namespace std;

class AbstractFruit{
public:
    virtual void showName()=0;
    virtual ~AbstractFruit(){cout << "AbstractFruit Destruct"<< endl;}
};

class Apple : public AbstractFruit{
public:
    virtual void showName(){
        cout << "Apple" << endl;
    }
    ~Apple(){cout << "Apple Destruct"<< endl;}
};

class Banana : public AbstractFruit{
public:
    virtual void showName(){
        cout << "Banana" << endl;
    }
    ~Banana(){cout << "Banana Destruct"<< endl;}
};

//水果工厂
class FactoryFruit{
public:
    AbstractFruit* createFruit(string fruitname){
        if(fruitname=="apple"){
            return new Apple;
        }else if(fruitname=="banana"){
            return new Banana;
        }else 
            return nullptr;
    }
};

void test01(){
    FactoryFruit* factory = new FactoryFruit;
    AbstractFruit* absFruit;
    absFruit = factory->createFruit("apple");
    absFruit->showName();
    delete absFruit;
    absFruit = factory->createFruit("banana");
    absFruit->showName();
    delete absFruit;
    delete factory;
}


int main(){
    test01();
    return 0;
}