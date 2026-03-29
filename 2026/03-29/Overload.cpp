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


int main()
{
  
  return 0;
}
