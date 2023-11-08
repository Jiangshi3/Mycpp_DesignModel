#include <iostream>
using namespace std;

void test01(){
    int a=1;
    int b=2;
    int& c = a;
    int* d = &b;
    cout << "&a=" << &a << endl;  //0x61fddc
    cout << "&b=" << &b << endl;  //0x61fdd8
    cout << "c=" << c << endl;    // 1
    cout << "&c=" << &c << endl;  // 0x61fddc
    cout << "d=" << d << endl;    // 0x61fdd8
    cout << "*d=" << *d << endl;  // 2
}

int main()
{
    test01();
    return 0;
}

/*

'*' 运算符（解引用操作符）：
    在声明中：T *ptr; 声明了一个指向类型 T 的指针，其中 * 是指针声明的一部分。
    在使用时：*ptr 表示解引用操作，用于访问指针 ptr 所指向的对象的值。
'&' 运算符（取地址操作符）：
    在声明中：T &ref = variable; 声明了一个引用 ref，它引用了类型为 T 的变量。
    在使用时：&variable 表示取地址操作，用于获取变量 variable 的内存地址。

'*' 用于解引用指针，以访问指针所指向的对象。  '*'操作的对象时指针。
'&' 用于获取对象的内存地址，以创建指向该对象的指针，或者用于声明引用。

*/

