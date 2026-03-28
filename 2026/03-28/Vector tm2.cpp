/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。
nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。

判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。

示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4,_,_,_,_,_]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
 

提示：

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums 已按 非递减 顺序排列。
*/

//my code
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cmp = nums[0];
        for(int i = 1; i < nums.size(); i ++)
          //一开始忘记更新数组长度导致死循环
        {
            if(nums[i] == cmp)
            {
                nums.erase(nums.begin() + i);
              //效率极其低下，因为erase函数是把数组元素整体往前移
                i --;
            }
            else
            {
                cmp = nums[i];
            }
        }
        return nums.size();
    }
};

//AI code
#include <vector>
using namespace std;
//什么究极思路，我滴个老天啊
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // 空数组直接返回长度0

        int writeIndex = 1;  // 写指针，指向下一个要写入非重复元素的位置

        // 从第二个元素开始遍历
        for (int readIndex = 1; readIndex < nums.size(); ++readIndex) {
            // 如果当前元素和前一个元素不同，说明是新的非重复元素
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];  // 写入写指针位置
                writeIndex++;  // 写指针前移
            }
            // 如果相同，跳过，不动写指针
        }
//只用遍历一次啊
        return writeIndex; // 写指针的值就是去重后的长度
    }
};
