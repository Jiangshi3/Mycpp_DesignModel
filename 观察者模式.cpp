/*
    观察者模式
    本例场景：几个英雄打boss。
    
    观察者模式是用于建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，其他对象将相应作出反应。
    在观察者模式中，发生改变的对象称为**观察目标**，而被通知的对象称为**观察者**，一个观察目标可以对应多个观察者。
*/
#include <iostream>
#include <list>
using namespace std;


//抽象的英雄(观察者)
class AbstractHero{
public:
    virtual void update() = 0;
    virtual ~AbstractHero(){};
};
//具体的英雄(观察者)
class HeroA : public AbstractHero{
public:
    HeroA(){
        cout << "HeroA fighting" << endl;
    }
    virtual void update() {
        cout << "HeroA stop fighting" << endl;
    }
};
class HeroB : public AbstractHero{
public:
    HeroB(){
        cout << "HeroB fighting" << endl;
    }
    virtual void update() {
        cout << "HeroB stop fighting" << endl;
    }
};
class HeroC : public AbstractHero{
public:
    HeroC(){
        cout << "HeroC fighting" << endl;
    }
    virtual void update() {
        cout << "HeroC stop fighting" << endl;
    }
};

//抽象的观察目标
class AbstractBoss{
public:
    //添加观察者
    virtual void addHero(AbstractHero* Hero) = 0;
    //删除观察者
    virtual void deleteHero(AbstractHero* Hero) = 0;
    //通知观察者
    virtual void notify() = 0;
    virtual ~AbstractBoss(){};
};
//具体的观察目标
class BossA : public AbstractBoss{
public:
    virtual void addHero(AbstractHero* Hero){
        pList.push_back(Hero);
    }

    virtual void deleteHero(AbstractHero* Hero){
        pList.remove(Hero);
    }

    virtual void notify(){
        for(auto iter=pList.begin(); iter!=pList.end(); ++iter){
            (*iter)->update();
        }
    }
private:
   list<AbstractHero*> pList;
};

void test01(){
    //创建观察则
    AbstractHero* heroa = new HeroA;
    AbstractHero* herob = new HeroB;
    AbstractHero* heroc = new HeroC;
    //创建观察目标
    AbstractBoss* bossa = new BossA;

    bossa->addHero(heroa);
    bossa->addHero(herob);
    bossa->addHero(heroc);
    cout << "HeroB died" << endl;
    bossa->deleteHero(herob);
    cout << "BOSS died!  victory! " << endl;
    bossa->notify();

    delete heroa;
    delete herob;
    delete heroc;
    delete bossa;
}

int main(){
    test01();

    return 0;
}