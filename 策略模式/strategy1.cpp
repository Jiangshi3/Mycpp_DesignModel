/*
    计算不同国家的税法；
    不采用设计模式的版本
*/
#include <iostream>
using namespace std;

enum TaxBase{
    CN_Tax,
    US_Tax,
    DE_Tax   //更改
};

class SalesOrder{
private:
    TaxBase Tax;
public:
    double CaculateTax(){
        // 条件判断语句； 有时候支持不适用的算法也是一种性能负担；
        if(Tax==CN_Tax){
            // CN*****
            return 999;
        }
        else if(Tax==US_Tax){
            // US*****
        }
        else if(Tax==DE_Tax){  // 更改
            // DE*****
        }
    }

    void setCNTax(){
        Tax=CN_Tax;
    }
};

int main(){

    SalesOrder a;
    a.setCNTax();
    cout << a.CaculateTax() << endl;

    return 0;
}


