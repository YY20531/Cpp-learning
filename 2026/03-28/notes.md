# 📆2026-3-28

## 1.学习了单例模式

### 🤔 个人理解
- 怎么说呢，这东西作用应该就是创建一个全局共享的实例，不允许有拷贝或是赋值
- 构造函数私有化，直接禁用拷贝和赋值
- 有点天上地下，唯我独尊的感觉。

### 🔧 相关知识点
<details>
<summary> 拷贝构造函数</summary> 
  
- classname(const classname &other);
- 拷贝构造函数是“在需要复制对象时被调用”的，而不是自动乱调用的
  
</details>

<details>
<summary> static的用法</summary>


| 作用域        | 特点         |
| ---------- | ---------- |
| 函数内static  | 延续变量，限制作用域 |
| 类内static   | 类共享，不属于对象  |
| 文件全局static | 限制作用域到文件   |

静态函数无法访问非静态变量

类里的静态变量要全局初始化

typename classname :: x = 0;

</details>


<details>
<summary>🔥 深入理解（以后补）</summary>

（先空着）

</details>


## 2.
