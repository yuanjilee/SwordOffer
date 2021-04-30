#include <iostream>
#include <stack>
using namespace std;
/**
 * 题目：写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 * 输入：1,2  输出 3
 * 考点：位运算
 * 分析：可以想想计算机是如何以二进制存储我们的运算的
 */

/**
 * 解法一：
 * 时间复杂度：
 */

class Solution {
   public:
    int Add(int num1, int num2) {
        while (num2 != 0) {
            // 负数左移会在低位补1，所以转化为无符号整数
            int temp = num1 ^ num2;
            num2 = (num1 & num2) << 1;
            num1 = temp;
        }
        return num1;
    }
};

/**
 * 解法二：
 * 时间复杂度：
 */
class Solution2 {
   public:
};

int main() {
    cout << Solution().Add(1, 2) << endl;
    return 0;
}