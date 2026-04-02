# Cons && Des


构造函数 → 申请资源

使用对象

析构函数 → 释放资源

## Constructor
- 普通构造 → 创建

```c++
class A {
public:
    int x;

    A(int val) : x(val) {}
    //初始化列表(const / 引用成员只能如此初始化)
};
```

- 拷贝构造 → 复制
```c++
class A {
public:
    int x;

    A(const A& other) : x(other.x) {}
};

void func(A x);
func(a);   // ✔ 拷贝构造（传值）
//默认浅拷贝
```

- 移动构造 → 转移
```c++
class A {
public:
    int* p;

    A(A&& other) : p(other.p) {
        other.p = nullptr; // ⚠️ 必须, 否则析构会double free
    }
};
```

- 委托构造 → 复用
```c++
class A {
public:
    int x, y;

    A(int a, int b) : x(a), y(b) {}

    A(int a) : A(a, 0) {}  // 委托
};
```


<details>
<summary> PS:左右值 </summary>

- 左值（lvalue）  → 有名字，可以反复用
- 右值（rvalue） → 临时的，用完就没了

| 写法    | 绑定对象 |
| ----- | ---- |
| `T&`  | 左值   |
| `T&&` | 右值   |

- 👉 1️⃣ && = 右值引用（专门接临时对象）

- 👉 2️⃣ std::move = 把左值变成右值（只是转换）//#include <utility>， 本质类型转换函数

- 👉 3️⃣ 移动构造 = 利用这个机制偷资源
</details>


## 析构

     析构函数 = 对象“死亡时”自动调用，用来释放资源
- 语法:
```c++
#include <iostream>
using namespace std;

class A {
public:
    ~A() {
        cout << "对象被销毁\n";
    }
};

int main() {
    A a;
}  // 👉 这里自动调用 ~A()
```
- 何时调用？
    1. 作用域结束
    2. 函数结束
    3. delete时(配合new)
