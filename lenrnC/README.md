# c++温习笔记（只记录了一些难以理解的)

## 基本语法
* C++ 语言定义了一些头文件，这些头文件包含了程序中必需的或有用的信息。上面这段程序中，包含了头文件 <iostream>。
* 下一行 using namespace std; 告诉编译器使用 std 命名空间。命名空间是 C++ 中一个相对新的概念。std 是标准库函数使用的命名空间，是 standard（标准）的缩写。
using name space std ，它声明了命名空间 std，后续如果有未指定命名空间的符号，那么默认使用 std，这样就可以使用 cin、cout、vector 等(否则就需要std:: cout)。


## 数据类型
* bool
* char
* int
* float
* double
* void
* wchar_t


### 类型修饰符
* signed
* unsigned
* short
* long


### 类型限定符
* const const 类型的对象在程序执行期间不能被修改改变。
* volatile 告诉编译器，变量的值可能以程序未明确指定的方式被改变。强制程序每次都去内存中取值。多线程中用。
* restrict 由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符

### typedef 声明
可以使用 typedef 为一个已有的类型取一个新的名字

### 枚举类型
如果一个变量只有几种可能的值，可以定义为枚举(enumeration)类型。所谓"枚举"是指将变量的值一一列举出来，变量的值只能在列举出来的值的范围内。

### 变量声明
如果你在main中定义了函数a，但是a中main函数下面写的，就需要提前声明函数a
```extern int a, b;```

### C++ 中的左值（Lvalues）和右值（Rvalues）
C++ 中有两种类型的表达式：

* 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
* 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

## 定义常量（c++里面一般用const）
* 类型和安全检查不同
宏定义是字符替换，没有数据类型的区别，同时这种替换没有类型安全检查，可能产生边际效应等错误；
const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查
* 编译器处理不同
宏定义是一个"编译时"概念，在预处理阶段展开，不能对宏定义进行调试，生命周期结束与编译时期；
const常量是一个"运行时"概念，在程序运行使用，类似于一个只读行数据
* 存储方式不同
宏定义是直接替换，不会分配内存，存储与程序的代码段中；
const常量需要进行内存分配，存储与程序的数据段中
* 定义域不同
```
	void f1 ()
	{
	    #define N 12
	    const int n 12;
	}
	void f2 ()
	{
	    cout<<N <<endl; //正确，N已经定义过，不受定义域限制
	    cout<<n <<endl; //错误，n定义域只在f1函数中
	}
```
* 定义后能否取消
宏定义可以通过#undef来使之前的宏定义失效
const常量定义后将在定义域内永久有效
* 是否可以做函数参数
宏定义不能作为参数传递给函数
const常量可以在函数的参数列表中出现

#### \#efine宏定义
```#define LENGTH 10  ```

#### const
```const int  LENGTH = 10;```
定义成 const 后的常量，程序对其中只能读不能修改

## 存储类
* static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此， static 修饰局部变量可以在函数调用之间保持局部变量的值。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。
* extern 存储类 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。
* thread_local 存储类
使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。

## 位运算符

|运算符|	描述             |	实例                  |
|-----|:-----------------:|:----------------------:|
|&	|如果同时存在于两个操作数中，二进制 AND 运算符复制一位到结果中。|	(A & B) 将得到 12，即为 0000 1100|
|\|	|如果存在于任一操作数中，二进制 OR 运算符复制一位到结果中。|	(A | B) 将得到 61，即为 0011 1101|
|^|	如果存在于其中一个操作数中但不同时存在于两个操作数中，二进制异或运算符复制一位到结果中。|	(A ^ B) 将得到 49，即为 0011 0001|
|~|	二进制补码运算符是一元运算符，具有"翻转"位效果，即0变成1，1变成0。|	(~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式。|
|<<	|二进制左移运算符。左操作数的值向左移动右操作数指定的位数。|	A << 2 将得到 240，即为 1111 0000|
|>>	|二进制右移运算符。左操作数的值向右移动右操作数指定的位数。|	A >> 2 将得到 15，即为 0000 1111|

## 杂项运算符
|运算符|	描述                               |
|-----|:---------------------------------------:|
|sizeof|	sizeof 运算符返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。|
|Condition ? X : Y|	条件运算符。如果 Condition 为真 ? 则值为 X : 否则值为 Y。|
|,	|逗号运算符会顺序执行一系列运算。整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值。|
|.（点 左边必须为实体）和 ->（箭头 左边必须为指针）|	成员运算符用于引用类、结构和共用体的成员。|
|Cast	|强制转换运算符把一种数据类型转换为另一种数据类型。例如，int(2.2000) 将返回 2。|
|取地址运算符 &	|指针运算符 & 返回变量的地址。例如 &a; 将给出变量的实际内存地址。|
|间接寻址运算符 *	|指针运算符 * 指向一个变量（内存地址）。例如，*var; 将指向变量 var（该内存地址中的值）。|

### goto 语句
goto 语句允许把控制无条件转移到同一函数内的被标记的语句。在任何编程语言中，都不建议使用 goto 语句。goto 语句一个很好的作用是退出深嵌套例程。
```
for(...) {
   for(...) {
      while(...) {
         if(...) goto stop;
         .
         .
         .
      }
   }
}
stop:
cout << "Error in program.\n";
```

## 函数

### 函数声明
函数声明会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。以下是函数声明：

```int max(int num1, int num2);```

当您在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的。在这种情况下，您应该在调用函数的文件顶部声明函数。

### 函数参数
* 传值调用	该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数对实际参数没有影响。(传入变量)
* 指针调用	该方法把参数的地址复制给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。（传入指针）
* 引用调用	该方法把参数的引用复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。（传入变量）

### Lambda 函数与表达式

具体形式如下:
```
[capture](parameters)->return-type{body}
```
```
[](int x, int y){ return x < y ; }
```

### C++ 数学运算
引用数学头文件 <cmath>

* double cos(double);
该函数返回弧度角（double 型）的余弦。
* double sin(double);
该函数返回弧度角（double 型）的正弦。
* double tan(double);
该函数返回弧度角（double 型）的正切。
* double log(double);
该函数返回参数的自然对数。
* double pow(double, double);
假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。
* double hypot(double, double);
该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。
* double sqrt(double);
该函数返回参数的平方根。
* int abs(int);
该函数返回整数的绝对值。
* double fabs(double);
该函数返回任意一个十进制数的绝对值。
* double floor(double);
该函数返回一个小于或等于传入参数的最大整数。

#### C++ 随机数
关于随机数生成器，有两个相关的函数。一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
######原型： void srand(unsigned seed);
######用法：它需要提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的随机数。如： srand(1); 直接使用 1 来初始化种子。不过为了防止随机数每次重复，常常使用系统时间来初始化，即使用 time 函数来获得系统时间，它的返回值为从 00:00:00 GMT, January 1, 1970 到现在所持续的秒数，然后将 time_t 型数据转化为(unsigned)型再传给 srand 函数，即： srand((unsigned) time(&t)); 还有一个经常用法，不需要定义time_t型t变量,即： srand((unsigned) time(NULL)); 直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的t数据。
例子：

```
#include <stdlib.h>
#include <stdio.h>
#include <time.h> /*用到了time函数，所以要有这个头文件*/
#define MAX 10
 
int main( void)
{
    int number[MAX] = {0};
    int i;
    srand((unsigned) time(NULL)); /*播种子*/
    for(i = 0; i < MAX; i++)
    {
        number[i] = rand() % 100; /*产生100以内的随机整数*/
        printf("%d ", number[i]);
    }
    printf("\n");
    return 0;
}
```

## c++数组
在 C++ 中要声明一个数组，需要指定元素的类型和元素的数量

``` type arrayName [ arraySize ];```

在C++中，setw(int n)用来控制输出间隔,（n-1个空格）

######Array 是固定大小的，不能额外增加元素.当我们想定义不固定大小的字符时,可以使用 vector(向量) 标准库。

### C++ 指向数组的指针

```double balance[50];```
balance 是一个指向 &balance[0] 的指针，即数组 balance 的第一个元素的地址。
#### C++ 传递数组给函数

* 方式 1 形式参数是一个指针：```void myFunction(int *param)```
* 方式 2 形式参数是一个已定义大小的数组： ```void myFunction(int param[10])```
* 方式 3 形式参数是一个未定义大小的数组：```void myFunction(int param[])```

#### C++ 从函数返回数组

C++ 不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
如果您想要从函数返回一个一维数组，您必须声明一个返回指针的函数，如下：

```
int * myFunction()
```
```
	int *p;
 
   p = getRandom();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }
```

### C++ 中的 String 类

需要```#include <string>```

string类提供了一系列针对字符串的操作，比如：

1. append() -- 在字符串的末尾添加字符
2. find() -- 在字符串中查找字符串
4. insert() -- 插入字符
5. length() -- 返回字符串的长度
6. replace() -- 替换字符串
7. substr() -- 返回某个子字符串

## C++ 指针 vs 数组

指针和数组是密切相关的。事实上，指针和数组在很多情况下是可以互换的。例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。

```
int  var[MAX] = {10, 100, 200};
int  *ptr;
// 指针中的数组地址
ptr = var;
for (int i = 0; i < MAX; i++)
{
  cout << "var[" << i << "]的内存地址为 ";
  cout << ptr << endl;
 
  cout << "var[" << i << "] 的值为 ";
  cout << *ptr << endl;
 
  // 移动到下一个位置
  ptr++;
 }
```
指针和数组并不是完全互换的
```
int  var[MAX] = {10, 100, 200};
*var = i;    // 这是正确的语法
var++;       // 这是不正确的
*(var + 2) = 500;  // 正确
```

### c++ 指针数组

char *names[MAX] 是指针数组, 它的本质是存储指针的数组, 既存储 char 类型的指针的数组, 数组内的每个元素都是一个指针指向一个存储 char 类型的地址
```
const char *names[MAX] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };

    for (int i = 0; i < MAX; i++) {
        cout << " --- names[i]              = " << names[i] << endl;
        cout << " --- *names[i]             = " << *names[i] << endl;
        cout << endl;
        cout << " --- (*names[i] + 1)       = " << (*names[i] + 1) << endl;
        cout << " --- (char)(*names[i] + 1) = " << (char)(*names[i] + 1) << endl;
        cout << " ------------------------------------ " << endl << endl << endl << endl;
    }```


### C++ 指向指针的指针（多级间接寻址）

指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。当一个目标值被一个指针间接指向到另一个指针时，访问这个值需要使用两个星号运算符

## C++ 引用

引用很容易与指针混淆，它们之间有三个主要的不同：

* 不存在空引用。引用必须连接到一块合法的内存。
* 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
* 引用必须在创建时被初始化。指针可以在任何时间被初始化。

为 i 声明引用变量	```int&    r = i;```
int& r = i; 和 int r = i; 不同之处应该是内存的分配吧，后者会再开辟一个内存空间

###### C++之所以增加引用类型， 主要是把它作为函数参数，以扩充函数传递数据的功能。

C++ 函数传参：

1. 将变量名作为实参和形参。这时传给形参的是变量的值，传递是单向的。如果在执行函数期间形参的值发生变化，并不传回给实参。因为在调用函数时，形参和实参不是同一个存储单元。// 同 c
2. 传递变量的指针。形参是指针变量，实参是一个变量的地址，调用函数时，形参(指针变量)指向实参变量单元。这种通过形参指针可以改变实参的值。// 同 c
3. C++提供了 传递变量的引用。形参是引用变量，和实参是一个变量，调用函数时，形参(引用变量)指向实参变量单元。这种通过形参引用可以改变实参的值。

例：
```
void swap(int& x, int& y);
int a = 100;
int b = 200;
swap(a, b);//两个值会交换
```

### C++ 把引用作为返回值
通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。C++ 函数可以返回一个引用，方式与返回一个指针类似。
当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。

例：

```
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // 返回第 i 个元素的引用
}
setValues(1) = 20.23;
```

* 以引用返回函数值，定义函数时需要在函数名前加 &
* 用引用返回一个函数值的最大好处是，在内存中不产生被返回值的副本。

#####引用作为返回值，必须遵守以下规则：

1. 不能返回局部变量的引用。主要原因是局部变量会在函数返回后被销毁，因此被返回的引用就成为了"无所指"的引用，程序会进入未知状态。
2. 不能返回函数内部new分配的内存的引用。虽然不存在局部变量的被动销毁问题，可对于这种情况（返回函数内部new分配内存的引用），又面临其它尴尬局面。例如，被函数返回的引用只是作为一 个临时变量出现，而没有被赋予一个实际的变量，那么这个引用所指向的空间（由new分配）就无法释放，造成memory leak。
3. 可以返回类成员的引用，但最好是const。主要原因是当对象的属性是与某种业务规则（business rule）相关联的时候，其赋值常常与某些其它属性或者对象的状态有关，因此有必要将赋值操作封装在一个业务规则当中。如果其它对象可以获得该属性的非常 量引用（或指针），那么对该属性的单纯赋值就会破坏业务规则的完整性。

## C++ 基本的输入输出

我们无法区分 cout、cerr 和 clog 的差异，但在编写和执行大型程序时，它们之间的差异就变得非常明显。所以良好的编程实践告诉我们，使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出。

#### 标准输出流（cout）
```cout << "Value of str is : " << str << endl;```
#### 标准输入流（cin）
```
char name[50];
 
cout << "请输入您的名称： ";
cin >> name;
cout << "您的名称是： " << name << endl;
```
#### 标准错误流（cerr）
```cerr << "Error message : " << str << endl;```
#### 标准日志流（clog）
```clog << "Error message : " << str << endl;```

## C++ 数据结构（结构体）

#### 定义结构

为了定义结构，您必须使用 struct 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下：

```
	struct type_name {
	member_type1 member_name1;
	member_type2 member_name2;
	member_type3 member_name3;
	.
	.
	} object_names;
	
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Books Book2;        // 定义结构体类型 Books 的变量 Book2
 
   // Book1 详述
   strcpy( Book1.title, "C++ 教程");
   strcpy( Book1.author, "Runoob"); 
   strcpy( Book1.subject, "编程语言");
   Book1.book_id = 12345;
```

#### 作为函数参数
```
void printBook( struct Books book )
{
   cout << "书标题 : " << book.title <<endl;
   cout << "书作者 : " << book.author <<endl;
   cout << "书类目 : " << book.subject <<endl;
   cout << "书 ID : " << book.book_id <<endl;
}
```

#### 指向结构的指针

```
struct Books *struct_pointer;
truct_pointer = &Book1;
struct_pointer->title;
```

#### typedef 关键字
在c++中用处不大，因为c中必须struct Books book1才能定义一个结构体，所以这种方式在c中简便（直接Books book1）

```
typedef struct
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}Books;

Books book1;
```

## C++ 日期 & 时间

C++ 标准库没有提供所谓的日期类型。C++ 继承了 C 语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。

结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：
```
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}
```

相关常用函数：

1.	time_t time(time_t *time);
该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 .1。
2.	char *ctime(const time_t *time);
该返回一个表示当地时间的字符串指针，字符串形式 day month year hours:minutes:seconds year\n\0。
3.	struct tm *localtime(const time_t *time);
该函数返回一个指向表示本地时间的 tm 结构的指针。
4.	clock_t clock(void);
该函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。如果时间不可用，则返回 .1。
5.	char * asctime ( const struct tm * time );
该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。
6.	struct tm *gmtime(const time_t *time);
该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。
7.	time_t mktime(struct tm *time);
该函数返回日历时间，相当于 time 所指向结构中存储的时间。
8.	double difftime ( time_t time2, time_t time1 );
该函数返回 time1 和 time2 之间相差的秒数。
9.	size_t strftime();
该函数可用于格式化日期和时间为指定的格式。

实例：

```
#include <iostream>
#include <ctime>
using namespace std;
// 基于当前系统的当前日期/时间
   time_t now = time(0);
   
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
 
   cout << "本地日期和时间：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
   
   //使用结构 tm 格式化时间:
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   cout << "1970 到目前经过秒数:" << now << endl;
   tm *ltm = localtime(&now);
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
```