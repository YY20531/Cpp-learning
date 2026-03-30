# 模模模模模板

     👉 模板是“类型参数化”的代码生成机制
## 基操
- 语法:
  ```c++
  template <typename T>
  
  template <class T> // 和 typename 完全一样，建议用上面的，语义更直接
  ```
- 特点:
  - 模板是用来编写与类型无关的通用代码，在***编译时***根据具体类型生成对应实现，是 STL 的基础
  - 模板不是类/函数，而是“生成类/函数的*蓝图*”

- 核心形式
  - 1.模板函数(使用时根据类型自动推导)
   ```c++
   template <typename T>
   T add(T a, T b)
   {
       return a + b;
   }
   ```
  - 2.模板类(一般必须手动指定类型)
   ```c++
   template <typename T>
   class Box
   {
   public:
       T value;
   };
   ```

## 作用

- 减少冗余代码的使用
- 👉 解决问题：

❌ 为每种类型写一套代码

✔️ 一套代码适配所有类型

👉 带来的好处：

1.代码复用

2.类型安全

3.高性能（编译期生成）

## question
q : 话说，模板对不同的数据类型的操作是相同的，那么那些容器在存数据的时候里面的方法对所有数据类型都是一样的？不是应该不一样吗？

a : 模板提供统一代码，但具体能否工作取决于类型是否支持所需操作.

## 深入

<details>
     <summary>夸张哦（有缘再会）🐶</summary>

### 1. 模板特化（Template Specialization）
- 为某些特定类型提供“专门实现”
- 包括：全特化、偏特化（类模板常见）

### 2. SFINAE（替换失败不是错误）
- 用来“筛选”模板是否可用
- 常用于限制类型（类似早期的约束机制）

### 3. 类型萃取（Type Traits）
- 通过 <type_traits> 判断类型性质
- 如：is_same / is_integral / remove_reference

### 4. 完美转发（Perfect Forwarding）
- 配合 `std::forward`
- 保留左值/右值属性（非常重要，面试常考）

### 5. 可变参数模板（Variadic Templates）
- 模板参数数量不固定
- 如：`template<typename... Args>`

### 6. Concepts（C++20）
- 给模板加“明确约束”（更现代写法）
- 替代 SFINAE，可读性更好

### 7. 模板元编程（Template Metaprogramming）
- 编译期计算（如递归模板）
- STL 和库底层大量使用

### 8. CRTP（奇异递归模板模式）
- `class Derived : public Base<Derived>`
- 用于静态多态、优化性能

### 9. 模板与 STL 设计思想
- 容器、算法、迭代器之间的配合
- 泛型编程的核心实践
</details>
