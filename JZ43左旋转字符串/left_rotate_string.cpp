#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：汇编语言中有一种移位指令叫做循环左移（ROL），
 * 现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 * 是不是很简单？OK，搞定它！
 * 输入："abcXYZdef",3  输出："XYZdefabc"
 * 考点：字符串
 * 分析：字符串移动要考虑其效率
 */

/**
 * 解法一：暴力法，借用 substr 截断后重新拼接
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    string LeftRotateString(string str, int n) {
        if (str.size() < n) return str;
        string pre_sub = str.substr(0, n);
        str = str.erase(0, n);
        return str + pre_sub;
    }
};

/**
 * 解法二：自己实现截断过程
 * 时间复杂度：
 */
class Solution2 {
   public:
    string LeftRotateString(string str, int n) {
        if (str.size() < n) return str;
        string ret;
        for (int i = n; i < str.size(); i++) {
            ret += str[i];
        }
        for (int i = 0; i < n; i++) {
            ret += str[i];
        }
        return ret;
    }
};

int main() {
    string s = Solution2().LeftRotateString("abcXYZdef", 3);
    cout << s << endl;
    return 0;
}