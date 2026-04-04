#include <iostream>
#include <utility>
#include <cstring> // ❗缺少这个头文件（strlen / strcpy_s）

using namespace std;

class Student
{
private:
    char* ID, * name, * address;
    int age;
public:
    Student() : age(18)
    {
        const char* str = "漩涡鸣人";
        const char* str2 = "木叶村";
        const char* str3 = "2024020001";

        ID = new char[strlen(str3) + 1];
        name = new char[strlen(str) + 1];
        address = new char[strlen(str2) + 1];

        strcpy_s(ID, strlen(str3) + 1, str3);
        strcpy_s(name, strlen(str) + 1, str);
        strcpy_s(address, strlen(str2) + 1, str2);

        cout << "漩涡鸣人调用了默认的构造函数！" << endl;
    }

    Student(const char* ID, const char* name, const char* address, int age)
    {
        this->ID = new char[strlen(ID) + 1];
        strcpy_s(this->ID, strlen(ID) + 1, ID);

        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->address = new char[strlen(address) + 1];
        strcpy_s(this->address, strlen(address) + 1, address);

        this->age = age;
        cout << name << "调用了带参数的构造函数！" << endl;
    }

    Student(const char* ID, const char* name) :Student(ID, name, "学院都市", 16)
    {
        cout << name << "委托带参数的构造函数构造对象！" << endl;
    }

    Student(const Student& other)
    {
        cout << other.Get_name() << "调用了拷贝构造函数！" << endl;

        this->ID = new char[strlen(other.getID()) + 1];
        strcpy_s(this->ID, strlen(other.getID()) + 1, other.getID()); // ⚠️ strlen 多次调用，效率低（小问题）

        this->name = new char[strlen(other.Get_name()) + 1];
        strcpy_s(this->name, strlen(other.Get_name()) + 1, other.Get_name());

        this->address = new char[strlen(other.getAddress()) + 1];
        strcpy_s(this->address, strlen(other.getAddress()) + 1, other.getAddress());

        this->age = other.getage();
    }

    Student(Student&& other)
    {
        // ❌❌❌ 这里是“伪移动构造”（本质是深拷贝）
        this->ID = new char[strlen(other.getID()) + 1];
        strcpy_s(this->ID, strlen(other.getID()) + 1, other.getID());

        this->name = new char[strlen(other.Get_name()) + 1];
        strcpy_s(this->name, strlen(other.Get_name()) + 1, other.Get_name());

        this->address = new char[strlen(other.getAddress()) + 1];
        strcpy_s(this->address, strlen(other.getAddress()) + 1, other.getAddress());

        this->age = other.getage();

        other.free(); // ⚠️ 强行清空对方（危险设计，不是真正move）

        cout << name << "调用了移动构造函数！" << endl;
    }

    ~Student()
    {
        if (name != nullptr)
            cout << name << "调用了析构函数" << endl;
        else
            cout << "空对象调用了析构函数" << endl;

        free(); // ⚠️ 依赖 free() 的正确性（但下面写错了）
    }

    void Inf_Print() const
    {
        cout << "ID: " << ID << ",  ";
        cout << "姓名: " << name << ",  ";
        cout << "年龄: " << age << ",  ";
        cout << "来自: " << address << endl;
    }

    char* Get_name() const
    {
        return name; // ⚠️ 不安全，外部可以修改内部数据（建议 const char*）
    }

    void Set_Inf(const char* ID, const char* name, const char* address, int age)
    {
        // ❌❌❌ 内存泄漏（没有 delete 原来的）
        this->ID = new char[strlen(ID) + 1];
        strcpy_s(this->ID, strlen(ID) + 1, ID);

        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->address = new char[strlen(address) + 1];
        strcpy_s(this->address, strlen(address) + 1, address);

        this->age = age;
    }

    void Set_ID(const char* ID)
    {
        // ❌ 内存泄漏
        this->ID = new char[strlen(ID) + 1];
        strcpy_s(this->ID, strlen(ID) + 1, ID);
    }

    void Set_name(const char* name)
    {
        // ❌ 内存泄漏
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    void free()
    {
        // ❌❌❌ 致命错误：应该用 delete[]
        delete ID;
        delete name;
        delete address;

        ID = nullptr;
        name = nullptr;
        address = nullptr;
    }

    char* getID() const
    {
        return ID; // ⚠️ 同样不安全
    }

    char* getAddress() const
    {
        return address; // ⚠️ 同样不安全
    }

    int getage() const
    {
        return age;
    }
};


int main()
{
    Student Naruto;
    Naruto.Inf_Print();
    Student Mikoto_Misaka("2024020002", "御坂美琴", "学院都市", 16);
    cout << Mikoto_Misaka.Get_name() << "在内存中的地址是：" << &Mikoto_Misaka << endl;
    Mikoto_Misaka.Inf_Print();

    Student Sasuke_Uchiha(Naruto);
    Sasuke_Uchiha.Set_ID("2024020003");
    Sasuke_Uchiha.Set_name("宇智波佐助");
    Sasuke_Uchiha.Inf_Print();

    Student Shirai_Kuroko("2024020004", "白井黑子");
    Shirai_Kuroko.Inf_Print();
    
    Student Sister_Misaka_I=std::move(Mikoto_Misaka);
    Sister_Misaka_I.Inf_Print();
    Sister_Misaka_I.Set_Inf("2024020005", "御坂妹", "学院都市", 1);
    Sister_Misaka_I.Inf_Print();
    
    return 0;
}
