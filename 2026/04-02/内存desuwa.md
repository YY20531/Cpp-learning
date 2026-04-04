# 内存管理

<details>
  <summary> 😆内存四区</summary>


| 区域 | 存储内容 | 管理方式 | 生命周期 | 是否可修改 | 典型示例 | 注意事项 |
|------|--------|--------|--------|----------|--------|--------|
| 栈区（stack） | 局部变量、函数参数 | 编译器自动分配/释放 | 作用域内 | ✔ | `int a = 10;` | ❗不能返回局部变量地址（会变野指针） |
| 堆区（heap） | 动态分配内存 | 程序员手动管理（new/delete） | 手动控制 | ✔ | `int* p = new int(10);` | ❗必须 delete，否则内存泄漏 |
| 全局/静态区 | 全局变量、static变量 | 程序自动管理 | 程序运行期间 | ✔ | `int g; static int s;` | 程序结束时统一释放 |
| 常量区（只读区） | 字符串字面量、只读常量 | 程序管理 | 程序运行期间 | ❌ | `"hello"` | ❗修改会崩溃 |

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
