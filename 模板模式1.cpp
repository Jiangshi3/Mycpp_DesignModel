/*晚绑定
Library 早
Application 晚
Library调用Application
*/

#include <iostream>
using std::cout;
using std::endl;

//Library开发人员
class Library{
public:
    //这个run()是稳定的； template method
    void run(){  //程序主流程
        Step1();
        if(Step2()){  // 支持变化===>虚函数的多态调用
            Step3();
        }
        Step4();
        Step5();
    }
    virtual ~Library(){}  //基类的析构函数声明为虚函数

protected:
    void Step1(){  //稳定
        cout << "Step1" << endl;
    }

    void Step3(){
        cout << "Step3" << endl;
    }

    void Step5(){
        cout << "Step5" << endl;
    }

    virtual bool Step2()=0;  //变化
    virtual void Step4()=0;  //变化
};

//Application开发人员
class Application:public Library{
public:
    virtual bool Step2(){
        // 子类重写实现
        cout << "子类的 Step2" << endl;
        return true;
    }

    virtual void Step4(){
        // 子类重写实现
        cout << "子类的 Step3" << endl;
    }
};


int main(int argc, const char* argv[])
{
    Library* ptr = new Application;  // 这是个多态指针
    ptr->run();

    delete ptr;

    return 0;
}
