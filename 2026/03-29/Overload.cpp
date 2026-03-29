#include <iostream>
//name 相同，干的事不同
/*
重载（Overload）
├── 函数重载（核心）
│   ├── 普通函数
│   ├── 成员函数
│   ├── 构造函数
│   └── const 重载
│
└── 运算符重载（特殊形式的函数重载）
*/

//1.函数的重载

//函数名相同，参数不同即视为重载，与返回值无关
//emmmmm,我也要重载吗？
//对。
int add(int a, int b)
{
  return a + b;
}

float add(float a, float b)
{
  return a + b;
}
//ps:和函数模板的区别:
/*
👉 “这几种类型，代码能不能一模一样？”

能 👉 模板
不能 👉 重载
*/

//2.运算符的重载:fire
/*语法
class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
    //成员函数版本
};

friend Point operator+(const Point&, const Point&);
//非成员函数版本 + 友元函数。。。。。。写在类外
表达式左边变量类型
同类则用可用成员函数，非同类则必须用非成员函数


这知识点连接的真紧密吧，就决定是你了，友元函数！

a + b
⬇
a.operator+(b)
*/

int main()
{
  
  return 0;
}
