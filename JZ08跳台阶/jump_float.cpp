#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * 输入：
 * 考点：递归
 * 分析：
 */

/**
 * 解法一：找规律  1 2 3 5 7 斐波那契数列.
 * 也可以想，我在第n可台阶，那么我有两种方式,要么在 n-1 台阶,要么在 n-2台阶.
 * 即 f(n) = f(n-1) + f(n-2)
 * 时间复杂度：O(2^n)
 */

class Solution {
   public:
    int jumpFloor(int number) {
        if (number == 0 || number == 1) {
            return 1;
        } else {
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
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
    cout << Solution().jumpFloor(5) << endl;
    return 0;
}