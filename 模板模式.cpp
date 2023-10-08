/* 模板模式
背景：某个动物园，有一套固定的表演流程，但是其中有若干个表演子流程受欢迎程度比较低，希望将这几个表演流程创新，以尝试迭代更新表演流程。
*/
#include <iostream>
using namespace std;

// 职责    Zooshow有一个完备的表演
// 接口隔离原则
// 变化点 稳定点；   （骨架/固定的流程是稳定点； virtual的四个方法让子类去覆写是变化点）
// 先找出变化点和稳定点，再将变化点扩展出去；  扩展方法：1、继承（此处的流程固定，选择用继承）； 2、组合； （组合优于继承）
class ZooShow
{
public:
    void Show(){
        Show0();
        Show1();
        Show2();
        Show3();
    }
// 不希望暴露下面的接口，但希望子类可以访问；所以设置为protected；
protected:
    virtual void Show0(){
        cout << "Show0" << endl;
    }
    virtual void Show1(){
        cout << "Show1" << endl;
    }
    virtual void Show2(){
        cout << "Show2" << endl;
    }
    virtual void Show3(){
        cout << "Show3" << endl;
    }
};

class ZooShowEx : public ZooShow
{
public:
    virtual void Show1(){
        cout << "subclass Show1" << endl;
    }
    virtual void Show3(){
        cout << "subclass Show3" << endl;
    }
};


int main(int argc, char* argv[])
{
    ZooShow* zs = new ZooShowEx;  // 创新后的，调用基类的show(),其中一些函数被子类重写覆盖，调用的子类的show1().show3(); 
    zs->Show();

    ZooShow* zs_base = new ZooShow;  // 不希望被创新，调用基类的Show();
    zs_base->Show();

    delete zs;
    delete zs_base;

    return 0;
}





