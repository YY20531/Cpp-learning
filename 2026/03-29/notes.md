# 📓记录
>ps:今天好像有点水分，em，无伤大雅，I'm tired.🐶

## ⏲️ 1.时空复杂度分析

算法入门说是
只会暴力搜索😆

偶列诺time，多隆


## 🧰2.重载 + 友元函数
>和模板一起有说法吗？

### I think
- 函数重载
  - 不就是同名的函数，参数不同，
  - 来实现不同类型的变量的相似的功能吗
  - 返回值无关
- 运算符重载
  - 哇去，好烧脑啊
  - 本质是把运算符当成函数用？
  - 把运算符变成自己类的形状🔥
- 友元函数
  - 非成员函数通过友元函数来访问类内私有变量
  - 典中典之ostream& operator<<(ostream& os, const A& obj);
 >我说运算符重载和友元函数真是一对苦命鸳鸯🐦🐦

### 额外了解到的内容
<details>
<summary> cin, cout <<>> </summary>
  
---
  
- cout 👉 ostream 类型的对象
- cin 👉 istream 类型的对象

---

cout << a

⬇

调用 operator<<(cout, a)

⬇

返回 cout

⬇

继续 << b

>👉 cout / cin 是对象，而 << / >> 是对它们的运算符重载
</details>

---

<details>
<summary>函数模板(waiting for jiesuo)</summary>
  
---
  
模板（泛型编程）

│

├── 函数模板        → 生成函数

├── 类模板          → 生成类 ⭐⭐⭐

│

├── 模板特化        → 特殊处理

├── 非类型参数      → 参数不只是类型

└── 多参数模板      → 多种类型组合
</details>
