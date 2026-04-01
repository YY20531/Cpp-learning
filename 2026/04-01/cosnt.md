# How const uses

- 作用: 声明一个常量，通常无法被修改，直接进行改值等操作编译器会报错(仍有渠道可以绕过限制)
- 本质: 限制对象的访问方式，并非绝对不可变
- 用法:
  - 1. ` const int MAX_AGE = 90;//无法被修改`
    2.  ```c++
        //对于指针而言
        const int *p;// 无法修改指针指向的地址上的具体的值(const 与 int 的位置关系不重要,同时位于*左边即可)
        int * const q; //无法修改指针指向的地址
        ```
     3. ```c++
        /*对于类而言
        将一个成员函数标记为不对类内成员进行任何修改
        本质：
          - this 指针变为：const Entity* const this
          👉 所以：
            不能修改成员变量, 只能调用 const 成员函数
        */
        class Entity
        {
        private:
          int a, b;
          const int c;
          mutable int d;
        public:
          Entity(int d, int e, int f) : a(d), b(e), c(f) {};
        //const的属性只能通过初始化列表来进行初始化
          /*
         原因：
          - const 成员变量必须在“创建时初始化”
          - 不能先创建再赋值
          */
          int get_a() const
        //表示不会对成员变量做任何操作
          {
            d = 2;
            //mutable 加持下的变量可以在const的方法中被修改
            return a;
          }
          void set_a(int a)
          {
            this->a = a;
          }
        };
        int main()
        {
          const Entity e;
          //只能调用const 成员函数，其他book
        }
        ```
    5. ```c++
       //函数参数中的const
       void print(const std::string& s);
       /*
       作用：
        - 防止函数内部修改参数
        - 避免拷贝（配合引用 &）

        👉 高频组合：const + 引用（&）
         既可普通，又可临时
       */
       print(10);//合理
       ```
