#include <iostream>
//🔥 单例 = private 构造 + static 实例 + 禁拷贝 + 唯一访问入口

class Singleton
{
private:
  Singleton(){};
//构造函数私有，防止外部创建对象
public:

  Singleton(const Singleton &) = delete;
//编译期彻底禁止拷贝构造函数，防止复制
  Singleton& operator=(const Singleton&) = delete;
//禁止赋值操作

  static Singleton &GetInstance()
//静态函数才能不依靠具体实例直接访问
//返回值应为所创建单例的引用，确保单例存在且唯一
  {
    static Singleton instance;
    //只创建一个实例
    return instance;
  }

  void Hello()
  {
    std::cout << "Hello World!" << std::endl;
  }
};

int main()
{
  Singleton::GetInstance().Hello();
  
  Singleton &s1 = Singleton::GetInstance();
  Singleton &s2 = Singleton::GetInstance();
  
  std::cout << ((&s1 == &s2) ? "true" : "false") << std::endl;
//🔥 判断“是不是同一个对象” → 一定比较地址
//结果为true，本质是同一个对象  
  return 0;
}
