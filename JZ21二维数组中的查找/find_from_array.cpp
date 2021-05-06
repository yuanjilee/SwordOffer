#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
  [1,2,8,9],
  [2,4,9,12],
  [4,7,10,13],
  [6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。
 * 输入：7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]  输出：true
 * 考点：数组
 * 分析：
 */

/**
 * 解法一：暴力法，遍历
 * 时间复杂度：O(n^2)
 */

class Solution {
   public:
    bool Find(int target, vector<vector<int>> array) {
        for (auto i : array) {
            for (auto j : i) {
                if (j == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * 解法二：二分法，找二分点：二分后应该还是二维数组，所以应该找右上角或者左下角
 * 时间复杂度：O(m+n)
 */
class Solution2 {
   public:
    bool Find(int target, vector<vector<int>> array) {
        int m = array.size();
        int n = array[0].size();
        if (m == 0 || n == 0) {
            return false;
        }
        int i = 0;
        int j = array[0].size() - 1;

        while (i < m && j >= 0) {
            int end = array[i][j];
            if (end == target) {
                return true;
            }

            else if (end > target) {
                j--;
            }

            else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> array = {
        {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout << Solution2().Find(7, array) << endl;
    return 0;
}