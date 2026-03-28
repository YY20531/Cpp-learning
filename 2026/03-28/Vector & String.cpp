/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 
提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 如果非空，则仅由小写英文字母组成
*/

//my code
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int len = strs.size();
        if(len == 0)
            return "";
        string result = "";
        int count = 0;//没用
        
        int min = strs[0].length();
        for(int i = 1; i < len; i ++)
        {
            int cmp = strs[i].length();
            min = min < cmp  ? min : cmp; 
        }//找最短字符串

        for(int j = 0; j < min; j ++)
        {
            char temp = strs[0][j];
            int pd = 1;
            for(int i = 1; i < len; i ++)
            {
                if(temp == strs[i][j]) continue;
                pd = 0;
                break;
            }//主逻辑
            if(pd)
            {
                result += temp;
            }
            else
            {
                break;
            }
        }
        return result;
    }
};
//AI code
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // 空数组直接返回空字符串

        // 找到最短字符串长度
        int minLen = INT_MAX;
        for (auto &s : strs) {
            minLen = min(minLen, (int)s.size());
        }//迭代器，66，等着

        string result;
        for (int j = 0; j < minLen; ++j) {
            char c = strs[0][j];  // 取第一个字符串的当前字符
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][j] != c) {
                    return result; // 一旦有不匹配，直接返回
                }
            }
            result.push_back(c); // 逐字符追加
        }

        return result; // 全部匹配，返回最长公共前缀
    }
};
