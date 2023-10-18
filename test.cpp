#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    array<int, 5> arr1{0};  //array不初始化，会有奇怪的数
	vector<int> res(5);
	for(int i=0;i<5;++i){
	cout << res[i] << " ---- " <<arr1[i]<< endl;
	}
	cout << &arr1[0] << endl;  //地址 0x61fdf0
    cout << arr1[0] << endl;   // 0
	cout << &arr1[1] << endl;  // 地址 0x61fdf4
	cout << &res << endl;      //地址
   cout << "Hello World";
   return 0;
}
