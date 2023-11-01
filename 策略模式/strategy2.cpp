// 含有多条条件判断语句大多要用到策略模式
#include <iostream>
using namespace std;

class Context{};

class TaxStrategy{
public:
    virtual double Caculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Caculate(const Context& context) override{
        // CN*******
    };
};

class USTax : public TaxStrategy{
public: 
    virtual double Caculate(const Context& context) override{
        // US******
    };
};

class SalesOrder{
private:
    TaxStrategy* strategy;
public:
    SalesOrder( /*..抽象_伪码..*/  ){
        /*....*/
    }
    ~SalesOrder(){
        /*....*/
    }

    double CaculateTax(){
        Context context;
        double val = strategy->Caculate(context); //多态调用
    }
};

