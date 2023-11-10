//更改版本后的策略模式
#include <iostream>
using namespace std;

class TaxStrategy{
public:
    virtual double Caculate()=0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Caculate() override{
        // CN*******
    };
};

class USTax : public TaxStrategy{
public: 
    virtual double Caculate() override{
        // US******
    };
};

class SalesOrder{
private:
    TaxStrategy* pStrategy;
public:
    SalesOrder(){}
    ~SalesOrder(){}
    void set(TaxStrategy* strategy){
        this->pStrategy = strategy;
    }
    double CaculateTax(){
        double val = pStrategy->Caculate(); //多态调用
        return val;
    }
};

void test(){
    TaxStrategy* pCNTax = new CNTax;
    TaxStrategy* pUSTax = new USTax;
    SalesOrder* pSale = new SalesOrder;
    pSale->set(pCNTax);
    cout << "CN:" << pSale->CaculateTax() << endl;

    pSale->set(pUSTax);
    cout << "US:" << pSale->CaculateTax() << endl;
    delete pCNTax;
    delete pUSTax;
    delete pSale;
}

int main(){
    test();

    return 0;
}
