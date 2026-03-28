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
| **信息**    | 🔥`size()`          | 返回元素个数                  | `v.size();`                                                             |
|           | 🔥`empty()`         | 判断是否为空                  | `v.empty();`                                                            |
|           | `capacity()`      | 返回当前容量                  | `v.capacity();`                                                         |
| **访问**    | `operator[]`      | 下标访问，不检查越界              | `v[0];`                                                                 |
|           | 🔥`at()`            | 下标访问，检查越界               | `v.at(0);`                                                              |
|           | `front()`         | 第一个元素                   | `v.front();`                                                            |
|           | `back()`          | 最后一个元素                  | `v.back();`                                                             |
| **增删**    |🔥 `push_back()`     | 尾部添加                    | `v.push_back(6);`                                                       |
|           |🔥 `pop_back()`      | 删除尾部                    | `v.pop_back();`                                                         |
|           | 🔥`insert()`        | 插入元素                    | `v.insert(v.begin()+2, 100);`                                           |
|           |🔥 `erase()`         | 删除元素/区间                 | `v.erase(v.begin()+1);`<br>`v.erase(v.begin()+1,v.begin()+3);`          |
|           | 🔥`clear()`         | 清空 vector               | `v.clear();`                                                            |
| **遍历**    | 下标遍历              | for + 索引                | `for(size_t i=0;i<v.size();++i) cout<<v[i];`                            |
|           | 迭代器遍历             | 使用 iterator             | `for(auto it=v.begin();it!=v.end();++it) cout<<*it;`                    |
|           | 范围 for            | C++11 语法                | `for(int x:v) cout<<x;`                                                 |
| **排序/反转** | 🔥`sort()`          | 升序/降序                   | `sort(v.begin(),v.end());`<br>`sort(v.begin(),v.end(),greater<int>());` |
|           | `reverse()`       | 反转顺序                    | `reverse(v.begin(),v.end());`                                           |
| **辅助**    | `resize()`        | 改变大小                    | `v.resize(10);`                                                         |
|           | `reserve()`       | 预留容量                    | `v.reserve(20);`                                                        |
|           | `shrink_to_fit()` | 收缩容量                    | `v.shrink_to_fit();`                                                    |
| **查找**    | 🔥`find()`          | 查找元素，返回迭代器              | `auto it=find(v.begin(),v.end(),3);`                                    |


</details>

>AI 还是太好用了😆

### 待定
<details>
<summary>迭代器是啥？（以后补）</summary>

指针？

</details>

## 3.string的了解

### 🤔function
<details>
<summary></summary>

| 操作类型     | 函数/方法                          | 功能                                           | 示例                                             |
| -------- | ------------------------------ | -------------------------------------------- | ---------------------------------------------- |
| **初始化**  | 构造函数                           | 声明空字符串 / 指定大小 / 默认字符                         | `string s1;`<br>`string s2(5,'a'); // "aaaaa"` |
|          | 从 C 字符串初始化                     | 将 char 数组转换为 string                          | `char str[]="hello"; string s3(str);`          |
|          | 拷贝构造                           | 复制另一个 string                                 | `string s4(s3);`                               |
| **长度信息** | 🔥`size()` / `length()`          | 字符串长度                                        | `s.size();`                                    |
|          | `empty()`                      | 是否为空                                         | `s.empty();`                                   |
| **访问字符** | `operator[]`                   | 下标访问，不检查越界                                   | `s[0];`                                        |
|          |🔥 `at()`                         | 下标访问，会检查越界                                   | `s.at(0);`                                     |
|          | `front()`                      | 第一个字符                                        | `s.front();`                                   |
|          | `back()`                       | 最后一个字符                                       | `s.back();`                                    |
| **增删**   | 🔥`push_back()`                  | 尾部添加字符                                       | `s.push_back('!');`                            |
|          |🔥 `pop_back()`                   | 删除尾部字符                                       | `s.pop_back();`                                |
|          | `append()`                     | 尾部添加字符串                                      | `s.append(" world");`                          |
|          | `insert()`                     | 插入字符串                                        | `s.insert(5, " C++");`                         |
|          | 🔥`erase()`                      | 删除字符或子串                                      | `s.erase(0, 5); // 从0开始删除5个字符`                 |
|          | 🔥`clear()`                      | 清空字符串                                        | `s.clear();`                                   |
| **查找**   |🔥 `find()`                       | 查找子串，返回下标                                    | `s.find("abc");`                               |
|          | `rfind()`                      | 从右向左查找子串                                     | `s.rfind("abc");`                              |
|          | `find_first_of()`              | 查找任意一个字符                                     | `s.find_first_of("aeiou");`                    |
|          | `find_last_of()`               | 从右查找任意字符                                     | `s.find_last_of("aeiou");`                     |
| **替换**   | 🔥`replace()`                    | 替换子串                                         | `s.replace(0,3,"xyz");`                        |
| **子串**   |🔥 `substr(pos,len)`              | 截取子串                                         | `s.substr(2,5); // 从2开始长度5`                    |
| **比较**   | `==, !=`                       | 字符串相等/不等                                     | `if(s1==s2)`                                   |
|          | `<, >`                         | 字典序比较                                        | `if(s1 < s2)`                                  |
|          | 🔥`compare()`                    | 返回比较结果                                       | `s1.compare(s2);`                              |
| **转换**   | `stoi()` / `stof()` / `stol()` | 字符串转整数/浮点                                    | `int x = stoi("123");`                         |
|          | `to_string()`                  | 数字转字符串                                       | `string s = to_string(456);`                   |
| **遍历**   | 下标遍历                           |                                                   | `for(size_t i=0;i<s.size();++i) cout<<s[i];` |
|          | 范围 for                         |                                                    | `for(char c:s) cout<<c;`                       |
| **修改大小** | `resize(n)`                    | 改变长度，多余截断，新增填字符                              | `s.resize(10,'x');`                            |
|          | `reserve(n)`                   | 预留容量，优化性能                                    | `s.reserve(50);`                               |
| **其他**   | `c_str()`                      | 返回 C 字符串                                     | `const char* p = s.c_str();`                   |
|          | 🔥`swap()`                       | 交换字符串                                        | `s1.swap(s2);`                                 |
|          | `reverse()` (algorithm)        | 反转字符串                                        | `reverse(s.begin(), s.end());`                 |


</details>

>u1s1,这两的函数还挺像，好吧，应该就是相同的，毕竟string也就是char类型的动态数组，
>只是在vector的基础上多了一些自己的方法，不赖🌭

