#include <iostream>
using namespace std;

int g = 20;

int test()
{
   g = 10;
   return g;
}

enum time
{
    first,second,third,forth,fifth
};

int main(){
    g=test();
    cout << g <<endl;
    g=30;
    cout << g <<endl;
    enum time a=fifth;
    cout << a <<endl;
       short int i;           // 有符号短整数
   short unsigned int j;  // 无符号短整数

   j = 50000;

   i = j;
   cout << i << " " << j;

   return 0;

}