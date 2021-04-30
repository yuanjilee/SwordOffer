#include <iostream>
#include <map>
#include <vector>
using namespace std;
/**
 * 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字是重复的。
 * 也不知道每个数字重复几次。请找出数组中任一一个重复的数字。
 * 存在不合法的输入的话输出-1

 * 输入：[2,3,1,0,2,5,3]  输出 2或3
 * 考点：数组
 * 分析：
 */

/**
 * 解法一：暴力法，遇到重复想字典
 * 时间复杂度：O(n)
 *
 */

class Solution {
   public:
    int duplicate(vector<int>& numbers) {
        map<int, int> map;
        for (auto n : numbers) {
            ++map[n];
            if (map[n] > 1) {
                return n;
            }
        }
        return -1;
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
    vector<int> v = {2, 3, 1, 0, 2, 5, 3};
    cout << Solution().duplicate(v) << endl;
    return 0;
}