#include <iostream>
#include <vector>
using namespace std;
/**
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
 * 求所有子数组的和的最大值。要求时间复杂度为 O(n).
 * 输入：[1,-2,3,10,-4,7,2,-5]   输出：18
 * 说明：输入的数组为{1,-2,3,10,—4,7,2,一5}，和最大的子数组为{3,10,-4,7,2}，
 * 因此输出为该子数组的和 18。
 * 考点：分治，动态规划
 * 分析：求子数组的最大值，因为有正有负，所以累加，当遇到负数对和进行判断，
 * 和为负，就丢弃重新累加。
 * 和为正，标记起来继续累加。标记值与最终结果比较大小。
 */

/**
 * 解法一：暴力法，遍历相加
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = array[0];
        int mark = 0;  // 一个标记值，用来计算累加
        for (const int ele : array) {
            if (mark + ele < 0) {  // <0，标记值归零
                mark = 0;
            } else {  // >0 继续累加
                mark += ele;
            }
            ret = max(ret, mark);
        }
        if (mark != 0) return ret;
        return *max_element(array.begin(), array.end());
    }
};

/**
 * 解法二：
 */
class Solution2 {
   public:
};

int main() {
    vector<int> v = {1, -2, 3, 10, -4, 7, 2, -5};
    cout << Solution().FindGreatestSumOfSubArray(v) << endl;
    return 0;
}