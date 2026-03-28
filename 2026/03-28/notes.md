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


## 2.对vector的学习
### 🍨opinion
- 666，不用自己管理内存的数组都来了，爽

### 常用操作
<details>
<summary>🐶 相关函数 </summary>
  
| 操作类型      | 函数/方法             | 功能                      | 示例                                                                      |
| --------- | ----------------- | ----------------------- | ----------------------------------------------------------------------- |
| **初始化**   | 构造函数              | 声明空 vector / 指定大小 / 默认值 | `vector<int> v1;`<br>`vector<int> v2(5);`<br>`vector<int> v3(5,10);`    |
|           | 区间构造              | 用数组或迭代器初始化              | `int arr[]={1,2,3}; vector<int> v(arr, arr+3);`                         |
|           | 拷贝构造              | 用另一个 vector 初始化         | `vector<int> v2(v1);`                                                   |
| **信息**    | `size()`          | 返回元素个数                  | `v.size();`                                                             |
|           | `empty()`         | 判断是否为空                  | `v.empty();`                                                            |
|           | `capacity()`      | 返回当前容量                  | `v.capacity();`                                                         |
| **访问**    | `operator[]`      | 下标访问，不检查越界              | `v[0];`                                                                 |
|           | `at()`            | 下标访问，检查越界               | `v.at(0);`                                                              |
|           | `front()`         | 第一个元素                   | `v.front();`                                                            |
|           | `back()`          | 最后一个元素                  | `v.back();`                                                             |
| **增删**    | `push_back()`     | 尾部添加                    | `v.push_back(6);`                                                       |
|           | `pop_back()`      | 删除尾部                    | `v.pop_back();`                                                         |
|           | `insert()`        | 插入元素                    | `v.insert(v.begin()+2, 100);`                                           |
|           | `erase()`         | 删除元素/区间                 | `v.erase(v.begin()+1);`<br>`v.erase(v.begin()+1,v.begin()+3);`          |
|           | `clear()`         | 清空 vector               | `v.clear();`                                                            |
| **遍历**    | 下标遍历              | for + 索引                | `for(size_t i=0;i<v.size();++i) cout<<v[i];`                            |
|           | 迭代器遍历             | 使用 iterator             | `for(auto it=v.begin();it!=v.end();++it) cout<<*it;`                    |
|           | 范围 for            | C++11 语法                | `for(int x:v) cout<<x;`                                                 |
| **排序/反转** | `sort()`          | 升序/降序                   | `sort(v.begin(),v.end());`<br>`sort(v.begin(),v.end(),greater<int>());` |
|           | `reverse()`       | 反转顺序                    | `reverse(v.begin(),v.end());`                                           |
| **辅助**    | `resize()`        | 改变大小                    | `v.resize(10);`                                                         |
|           | `reserve()`       | 预留容量                    | `v.reserve(20);`                                                        |
|           | `shrink_to_fit()` | 收缩容量                    | `v.shrink_to_fit();`                                                    |
| **查找**    | `find()`          | 查找元素，返回迭代器              | `auto it=find(v.begin(),v.end(),3);`                                    |


</details>

>AI 还是太好用了😆

### 待定
<details>
<summary>迭代器是啥？（以后补）</summary>

指针？

</details>
