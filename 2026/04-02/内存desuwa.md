# 内存管理

<details>
  <summary> 😆内存四区</summary>

  | 区域       | 谁管理    | 特点                |
| -------- | ------ | ----------------- |
| 栈（stack） | 编译器    | 自动分配/释放           |
| 堆（heap）  | 你（程序员） | 手动 `new / delete` |
| 全局区      | 程序     | 全局变量              |
| 常量区      | 程序     | 字符串字面量（只读）        |

</details>

- new & delete
  - 👉 new = 申请 + 构造
  ```c++
  int* p = new int;      // 未初始化（垃圾值）
  int* p2 = new int(10); // 初始化为10

  int* arr = new int[5];

  class A {
  public:
      A() { cout << "构造\n"; }
  };

  A* p = new A();
  ```
  - 👉 delete = 析构 + 释放
  ```c++
  int* p = new int(10);
  delete p;

  int* arr = new int[5];
  delete[] arr;
  //最好置空
  p = nullptr;
  arr = nullptr;
  ```
