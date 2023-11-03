#include <atomic>
#include <mutex>
using namespace std;


class singleton{
private:
    singleton(){}  //构造函数是私有的
    ~singleton(){}
    singleton(const singleton&){}
    singleton& operator=(const singleton&){}

    static singleton* Instance;
    static mutex lock_;
public:
    static singleton* getinstance();  //供用户获取单例的全局访问点
};

mutex singleton::lock_;
atomic<singleton*> Instance = nullptr;
singleton* singleton::getinstance() {
    if (Instance == nullptr) { 
        lock_guard<mutex> lock{ lock_ }; 
        if (Instance == nullptr) { 
            Instance = new singleton(); 
        }
    } 
    return Instance;
}

/*
由于上面的atomic需要一些性能上的损失，因此我们可以写一个优化的版本：
singleton* singleton::getinstance() {
    singleton* p = pInstance;
    if (p == nullptr) { 
        lock_guard<mutex> lock{ lock_ }; 
        if ((p=pInstance) == nullptr) { 
            pInstance = p = new singleton(); 
        }
    } 
    return p;
}




*/

