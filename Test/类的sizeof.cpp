//验证一个类有无virtual Function的大小
//answer：一个含有虚函数的基类派生一个类，不论这个类有没有自己虚函数，这个派生类也只有一个vptr，可见sizeof(),（不会有多个vptr，也浪费空间；）；
//（编译器可能把这个vptr放在class object的头或者尾部）,so每次在constructor时，要重新设定vptr的值，让其指向相应的vtbl。

#include <iostream>
using namespace std;

class A{
public:
    virtual void show(){
        cout<<"class A"<<endl;
    }
private:
    int* a;
    int b;
    static float num;  //静态变量不在class Object内
};
float A::num=99.99;

class B : public A {
public:
    virtual void show() override{
        cout<<"class B"<<endl;
    }
    virtual void funB(){
        cout << "funB" << endl;
    }
};

void test01(){
    cout << sizeof(A) << endl;  //两个sizeof()相等
    cout << sizeof(B) << endl;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

int main(){
    test01();
    return 0;
}

