# A small tiny note

- Rule of Three/Five
    - 拷贝构造
    - 拷贝赋值 
    - 析构
    - 移动构造
    - 移动赋值
```c++
class A {
    char* p;

public:
    A(const char* str = "") {
        p = new char[strlen(str) + 1];
        strcpy(p, str);
    }

    // 深拷贝
    A(const A& other) {
        p = new char[strlen(other.p) + 1];
        strcpy(p, other.p);
    }

    // 移动构造
    A(A&& other) {
        p = other.p;
        other.p = nullptr;
    }

    ~A() {
        delete[] p;
    }
};
```

<details>
<summary> 待深入理解</summary>

彩蛋？
</details>
