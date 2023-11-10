/*
    '提供一种代理控制对其他对象的访问'
    直接与代理打交道，代理里面封装了一个真正的实现。    
*/
#include <iostream>
using namespace std;

// 提供一个公共的接口
class AbstractCommonInterface{
public:
    virtual void run() = 0;
};
//写好的系统
class MySystem : public AbstractCommonInterface{
public:
    virtual void run(){
        cout << "system booting" << endl;
    }
};
//必须有权限验证，不是所有人都可以启动系统；提供用户名和密码；  与代理打交道；
class MySystemProxy : public AbstractCommonInterface{
public:
    MySystemProxy(string username, string password){
        this->mUsername = username;
        this->mPassword = password;
        pSystem = new MySystem;
    }
    ~MySystemProxy(){
        if(pSystem!=nullptr){
            delete pSystem;
        }
    }

    bool check(){
        if(mUsername=="admin" && mPassword=="admin"){
            return true;
        }
        return false;
    }

    virtual void run(){
        if(check()){
            cout << "pass the verification" << endl;
            pSystem->run();
        }else{
            cout << "The username or password is incorrect" << endl;
        }
    }
public:
    MySystem* pSystem;
    string mUsername;
    string mPassword;
};

void test01(){
    MySystemProxy* proxy = new MySystemProxy("admin", "admin");
    proxy->run();
}

int main(){
    test01();
    return 0;
}