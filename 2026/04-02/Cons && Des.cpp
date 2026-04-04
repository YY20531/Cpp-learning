#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

class Student
{
private:
    char* ID;
    char* name;
    char* address;
    int age;

    // 🔧 工具函数：拷贝字符串
    char* copy_str(const char* src)
    {
        if (!src) return nullptr;
        size_t len = strlen(src);
        char* p = new char[len + 1];
        strcpy_s(p, len + 1, src);
        return p;
    }

    // 🔧 释放资源
    void release()
    {
        delete[] ID;
        delete[] name;
        delete[] address;
        ID = name = address = nullptr;
    }

public:
    // 默认构造
    Student() : age(18)
    {
        ID = copy_str("2024020001");
        name = copy_str("漩涡鸣人");
        address = copy_str("木叶村");

        cout << "默认构造函数\n";
    }

    // 带参构造
    Student(const char* ID, const char* name, const char* address, int age)
    {
        this->ID = copy_str(ID);
        this->name = copy_str(name);
        this->address = copy_str(address);
        this->age = age;

        cout << name << " 调用带参构造\n";
    }

    // 委托构造
    Student(const char* ID, const char* name)
        : Student(ID, name, "学院都市", 16)
    {
        cout << name << " 委托构造\n";
    }

    // 🔥 拷贝构造（深拷贝）
    Student(const Student& other)
    {
        ID = copy_str(other.ID);
        name = copy_str(other.name);
        address = copy_str(other.address);
        age = other.age;

        cout << name << " 拷贝构造\n";
    }

    // 🔥 移动构造（真正 move）
    Student(Student&& other) noexcept
    {
        ID = other.ID;
        name = other.name;
        address = other.address;
        age = other.age;

        other.ID = other.name = other.address = nullptr;

        cout << (name ? name : "空") << " 移动构造\n";
    }

    // 🔥 拷贝赋值
    Student& operator=(const Student& other)
    {
        if (this == &other) return *this;

        release();

        ID = copy_str(other.ID);
        name = copy_str(other.name);
        address = copy_str(other.address);
        age = other.age;

        cout << name << " 拷贝赋值\n";
        return *this;
    }

    // 🔥 移动赋值
    Student& operator=(Student&& other) noexcept
    {
        if (this == &other) return *this;

        release();

        ID = other.ID;
        name = other.name;
        address = other.address;
        age = other.age;

        other.ID = other.name = other.address = nullptr;

        cout << (name ? name : "空") << " 移动赋值\n";
        return *this;
    }

    // 析构
    ~Student()
    {
        cout << (name ? name : "空对象") << " 析构\n";
        release();
    }

    // 打印
    void Inf_Print() const
    {
        cout << "ID: " << (ID ? ID : "null") << ", ";
        cout << "姓名: " << (name ? name : "null") << ", ";
        cout << "年龄: " << age << ", ";
        cout << "地址: " << (address ? address : "null") << endl;
    }

    // getter（安全）
    const char* Get_name() const { return name; }
    const char* getID() const { return ID; }
    const char* getAddress() const { return address; }
    int getage() const { return age; }

    // setter（防泄漏）
    void Set_name(const char* n)
    {
        delete[] name;
        name = copy_str(n);
    }

    void Set_ID(const char* id)
    {
        delete[] ID;
        ID = copy_str(id);
    }

    void Set_Inf(const char* id, const char* n, const char* addr, int a)
    {
        delete[] ID;
        delete[] name;
        delete[] address;

        ID = copy_str(id);
        name = copy_str(n);
        address = copy_str(addr);
        age = a;
    }
};


int main()
{
    Student Naruto;
    Naruto.Inf_Print();

    Student Mikoto("2024020002", "御坂美琴", "学院都市", 16);
    Mikoto.Inf_Print();

    Student Sasuke = Naruto; // 拷贝构造
    Sasuke.Set_name("宇智波佐助");
    Sasuke.Inf_Print();

    Student Kuroko("2024020004", "白井黑子");
    Kuroko.Inf_Print();

    Student Sister = std::move(Mikoto); // 移动构造
    Sister.Inf_Print();

    Student Test;
    Test = Sister; // 拷贝赋值

    Student Test2;
    Test2 = std::move(Sister); // 移动赋值

    return 0;
}
