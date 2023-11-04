/*
1. 抽象工厂类：工厂方法模式的核心类，提供创建具体产品的接口，由具体工厂类实现。

2. 具体工厂类：继承于抽象工厂，实现创建对应具体产品对象的方式。

3. 抽象产品类：它是具体产品继承的父类（基类）。

4. 具体产品类：具体工厂所创建的对象，就是此类。
*/

#include <iostream>
using namespace std;

//Shoes为鞋子的抽象类（基类），接口函数为Show()，用于显示鞋子。
class Shoes{
public:
    virtual void show()=0;
    virtual ~Shoes(){}
};
//具体类
class NikeShoes : public Shoes{
public:
    virtual void show() override{
        cout << "Nike shoes" << endl;
    }
};
//具体类
class LiningShoes : public Shoes{
public:
    virtual void show() override{
        cout << "Lining shoes" << endl;
    }
};


/*---------------------------------*/
//工厂基类
class ShoesFactory{
public:
    virtual Shoes* CreateShoes()=0;
    virtual ~ShoesFactory(){}
};
//具体工厂
class NikeFactory : public ShoesFactory{
public:
    virtual Shoes* CreateShoes() override{
        return new NikeShoes();
    }
};
//具体工厂
class LiningFactory : public ShoesFactory{
public:
    virtual Shoes* CreateShoes() override{
        return new LiningShoes();
    }
};

/*----------------------------------------*/

class MainForm{
private:
    ShoesFactory* factory;  //工厂
public:
    MainForm(ShoesFactory* factory){
        this->factory=factory;
    }
    void Button_click(){
        Shoes* shoesProducer = factory->CreateShoes();  //这个是多态new
        shoesProducer->show();
    }
};


int main(){
    // 鞋厂开设耐克生产线
    ShoesFactory *niKeProducer = new NikeFactory();
    // 耐克生产线产出球鞋
    Shoes *nikeShoes = niKeProducer->CreateShoes();
    // 耐克球鞋广告喊起
    nikeShoes->show();
    // 释放资源
    delete nikeShoes;
    delete niKeProducer;

    //没有使用到delete
    ShoesFactory* LiningProducer = new LiningFactory();
    MainForm m(LiningProducer);
    m.Button_click();
    delete LiningProducer;


    return 0;
}
