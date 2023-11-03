// DCLP双检测锁模式;
// 双重检查锁+自动回收
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class singleton {
private:
    singleton() {}

    static singleton *p;
    static std::mutex lock_;
public:
    static singleton *instance();

    // 实现一个内嵌垃圾回收类
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if(singleton::p)
                delete singleton::p;
        }
    };
    static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
};

singleton *singleton::p = nullptr;
singleton::CGarbo Garbo;
std::mutex singleton::lock_;

singleton* singleton::instance() {
    if (p == nullptr) {
        lock_guard<mutex> guard(lock_);
        if (p == nullptr)
            p = new singleton();
    }
    return p;
}

/*
DCLP的关键在于，大多数对instance的调用会看到p是非空的，因此甚至不用尝试去初始化它。
因此，DCLP在尝试获取锁之前检查p是否为空。只有当检查成功（也就是p还没有被初始化）时才会去获得锁，然后再次检查p是否仍然为空（因此命名为双重检查锁）。
第二次检查是必要，因为就像我们刚刚看到的，很有可能另一个线程偶然在第一次检查之后，获得锁成功之前初始化p。
*/

/*
DCLP不足：
看起来上述代码非常美好，可是过了相当一段时间后，才发现这个漏洞，原因是：内存读写的乱序执行(编译器问题)。
再次考虑初始化p的那一行： p = new singleton();
这条语句会导致三个事情的发生：

分配能够存储singleton对象的内存；
在被分配的内存中构造一个singleton对象；
让p指向这块被分配的内存。
可能会认为这三个步骤是按顺序执行的，但实际上只能确定步骤1是最先执行的，步骤2，3却不一定。问题就出现在这。

线程A调用instance，执行第一次p的测试，获得锁，按照1,3,执行，然后被挂起。此时p是非空的，但是p指向的内存中还没有Singleton对象被构造。
线程B调用instance，判定p非空， 将其返回给instance的调用者。调用者对指针解引用以获得singleton，噢，一个还没有被构造出的对象。bug就出现了。
DCLP能够良好的工作仅当步骤一和二在步骤三之前被执行，但是并没有方法在C或C++中表达这种限制。这就像是插在DCLP心脏上的一把匕首：
我们需要在相对指令顺序上定义限制，但是我们的语言没有给出表达这种限制的方法。
*/


