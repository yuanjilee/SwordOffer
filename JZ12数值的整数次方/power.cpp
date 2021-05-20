#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 保证base和exponent不同时为0。
 * 不得使用库函数，同时不需要考虑大数问题，也不用考虑小数点后面0的位数。
 * 输入：2.00000,3  输出 8.00000
 * 考点：数学
 * 分析：次方就是乘以自身
 */

/**
 * 解法一：暴力法
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    double Power(double base, int exponent) {
        if (base == 0) {
            return 0;
        }
        if (exponent == 0) {
            return 1;
        }
        double ret = base;
        for (int i = 0; i < abs(exponent) - 1; i++) {
            ret = ret * base;
        }
        return exponent > 0 ? ret : 1 / ret;
    }
};

/**
 * 解法二：利用二级制快速幂
 * 时间复杂度：O(logn)
 */
class Solution2 {
   public:
    double Power(double b, int n) {
        if (n < 0) {
            b = 1 / b;
            n = -n;
        }
        double x = b;  // 记录x^0, x^1, x^2 ...
        double ret = 1.0;
        while (n) {
            if (n & 1) {
                ret *= x;  // 二进制位数是1的，乘进答案。
            }
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};

int main() {
    cout << Solution().Power(1, 10) << endl;
    return 0;
}