#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，
 * 从同一个方向看总共有多少种不同的方法？
 * 输入：4  输出 5
 * 考点：递归，动态规划
 * 分析：
 */

/**
 * 解法一：归纳法  0 1 2 3 5 类斐波那契,优化见JZ7斐波那契
 * 时间复杂度：
 */

class Solution {
   public:
    int rectCover(int number) {
        if (number < 3) {
            return number;
        } else {
            return rectCover(number - 1) + rectCover(number - 2);
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
    cout << Solution().rectCover(4) << endl;
    return 0;
}