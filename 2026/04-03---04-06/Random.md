# 随机数啊随机数🐶

>本质为伪随机数

## How 伪随机数 works

1. 算法生成序列
   - PRNG 内部有一个状态（整数）
   - 算法根据当前状态计算下一个数 → 更新状态 → 输出数
   - 连续调用就生成了一串“伪随机数”
2. 种子决定起点
   - srand(seed) 或 C++11 default_random_engine(seed)
   - 种子初始化状态 → 决定序列的起点
   - 同种子 → 同序列（可复现）
   - 不同种子 → 不同起点 → 不同序列
3. 序列是有限的
   - 状态空间有限 → 序列最终会重复
   - 现代算法周期很长 → 在实际使用中近似无限
4. 获取随机数
   - 每次调用生成下一个数 → 类似从“序列的当前位置”取数
   - 种子不同 → “当前位置不同” → 输出不同

## 用法

### C风格
```c++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // 设置随机种子

    for(int i = 0; i < 5; i++) {
        int r = rand();          // 0 ~ RAND_MAX
        int r_mod = rand() % 100; // 0 ~ 99
        cout << r_mod << " ";
    }

    return 0;
}

```
- 特点
  - 简单、易用
  - 生成整数随机数
  - 分布不均匀（rand() % N 有偏差）
  - 序列可重复（相同种子）
  - 线程不安全
  - 周期较短（易重复）
 
### C++风格
```c++
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main() {
    // 1. 随机数生成器（算法）
    default_random_engine engine(time(0));

    // 2. 整数均匀分布
    uniform_int_distribution<int> dist_int(1, 100);
    cout << "整数随机数: " << dist_int(engine) << endl;

    // 3. 浮点均匀分布
    uniform_real_distribution<double> dist_real(0.0, 1.0);
    cout << "浮点随机数: " << dist_real(engine) << endl;

    // 4. 正态分布
    normal_distribution<double> dist_norm(0.0, 1.0);
    cout << "正态随机数: " << dist_norm(engine) << endl;

    return 0;
}
```
- 特点
  - 更现代化、灵活、安全
  - 可生成整数、浮点、正态、二项等分布
  - 序列可重复（同种子）
  - 可自定义随机数生成器，支持多线程安全
  - 周期极长，近似无限
  - 控制范围和分布更科学
 
### Comparsion

| 特性   | C 风格 rand()              | C++11 `<random>`                         |
| ---- | ------------------------ | ---------------------------------------- |
| 使用方式 | `rand()` + `srand(seed)` | `default_random_engine` + `distribution` |
| 支持分布 | 仅整数均匀                    | 整数、浮点、正态、二项等                             |
| 可重复性 | 可，通过种子                   | 可，通过种子                                   |
| 灵活性  | 差                        | 高                                        |
| 安全性  | 不均匀、线程不安全                | 均匀、线程安全可定制                               |
| 周期   | 较短                       | 极长（mt19937: 2^19937−1）                   |
