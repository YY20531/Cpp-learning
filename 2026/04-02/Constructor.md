# Cons && re

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
<summary> PS:左右值 <summary/>


<details/>


## 呃呃
