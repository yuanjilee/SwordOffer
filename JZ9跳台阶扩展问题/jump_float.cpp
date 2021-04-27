#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 考点：贪心
 * 分析：贪心点，假设再一下就可以跳到终点，那么它要跳多少台阶，是根据它当前多处的位置决定的。
 * 比如当前处在0->n, 1->n-1, 2->n-2,
 * 3->n-3；现假设，f(n)表示跳到第n个台阶所有的方法， 那么 f(n) = f(n-1) + f(n-2)
 * + f(0),而 f(n-1)同理可得，所以采用递归方法。
 */

/**
 * 解法一：递归
 * f(n) = f(n-1) + f(n-2) +...+ f(1) + f(0)
 * f(n-1) = f(n-1) + f(n-3) +...+ f(1) + f(0)
 * 相间，则 f(n) = 2*f(n-1)
 * 优点简单直白，缺点效率低
 * 时间复杂度：O(2^n)
 */
class Solution {
   public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1) {
            return 1;
        } else {
            return 2 * jumpFloorII(number - 1);
        }
    }
};

int main() {
    int n;
    Solution s = Solution();
    cout << "请输入 n:" << endl;
    cin >> n;
    cout << s.jumpFloorII(n) << endl;
    return 0;
}