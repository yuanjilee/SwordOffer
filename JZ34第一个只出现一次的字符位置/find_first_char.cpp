#include <iostream>
#include <map>
using namespace std;
/**
 * 题目：在一个字符串(0<=字符串长度<=10000，全部由字母组成)中
 * 找到第一个只出现一次的字符,并返回它的位置,
 * 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
 * 输入："google"   输出：4
 * 考点：字符串,哈希
 * 分析：看到重复出现的字符，应该想到字典，因为可以去重并做计数。
 */

/**
 * 解法一：暴力法，先字符串数组转换为字典 map<char, int>，
 * key 为出现的字符,value 为出现的次数。再次循环数组，找出value =1 的位置
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> map;
        for (char c : str) {
            ++map[c];
        }

        for (int i = 0; i < str.size(); i++) {
            if (map[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

/**
 * 解法二：
 */
class Solution2 {
   public:
};

int main() {
    string s = "google";
    cout << Solution().FirstNotRepeatingChar(s) << endl;
    return 0;
}