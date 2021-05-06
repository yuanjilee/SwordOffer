#include <iostream>
using namespace std;
/**
 * 题目：输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
 * 输入：10   输出 2
 * 考点：二进制的转换以及概念
 * 分析：转换为二进制并对1的个数计数，负数补码为源码各位取反+1
 */

/**
 * 解法一：通过除法转换（错误解法，判断负数出错）
 * 时间复杂度：
 */

class Solution {
   public:
    int NumberOf1(int n) {
        int m = abs(n);
        int count_0 = 0;
        int count_1 = 0;
        while (m != 0) {
            if (m % 2 == 0) {
                count_0++;
            } else {
                count_1++;
            }
            m = m / 2;
        }
        return n < 0 ? 32 - count_1 : count_1;  // 负数 + 1
    }
};

/**
 * 解法二：
 * 时间复杂度：O(n)
 */
class Solution2 {
   public:
    int NumberOf1(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};

int main() {
    cout << Solution2().NumberOf1(1) << endl;
    return 0;
}