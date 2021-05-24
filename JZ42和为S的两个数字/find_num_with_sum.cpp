#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/**
 * 题目：输入一个递增排序的数组和一个数字S，在数组中查找两个数，
 * 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 * 输入：[1,2,4,7,11,15],15  输出：[4,11]
 * 考点：数组，双指针
 * 分析：
 */

/**
 * 解法一：暴力法，遍历
 * 时间复杂度：O(n^2)
 */

class Solution {
   public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int size = array.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (array[i] + array[j] == sum) {
                    return {array[i], array[j]};
                }
            }
        }
        return {};
    }
};

/**
 * 解法二：哈希法
 * 时间复杂度：O(n)
 */
class Solution2 {
   public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) return vector<int>();
        int tmp = INT_MAX;
        pair<int, int> ret;
        unordered_map<int, int> mp;
        for (int i = 0; i < array.size();
             ++i) {  // 先将一个值以key添加到哈希表中
            mp[array[i]] = i;
        }
        for (int i = 0; i < array.size(); ++i) {  // 遍历找key和为sum的另一个值
            if (mp.find(sum - array[i]) != mp.end()) {
                int j = mp[sum - array[i]];
                if (j > i && array[i] * array[j] < tmp) {
                    tmp = array[i] * array[j];
                    ret = {i, j};
                }
            }
        }
        if (ret.first == ret.second) return vector<int>();
        return vector<int>({array[ret.first], array[ret.second]});
    }
};

/**
 * 解法三：因为是有序的，所以双指针法，两端向中间夹逼，
 * 注意判断乘积为最小
 * 时间复杂度：O(n)
 */
class Solution3 {
   public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) return vector<int>();
        int tmp = INT_MAX;
        pair<int, int> ret;
        int i = 0, j = array.size();
        while (i < j) {
            if (array[i] + array[j - 1] == sum) {
                if (array[i] * array[j - 1] < tmp) {
                    tmp = array[i] * array[j - 1];
                    ret = {i, j - 1};
                }
                ++i, --j;
            } else if (array[i] + array[j - 1] < sum) {
                ++i;
            } else {
                --j;
            }
        }
        if (ret.first == ret.second) return vector<int>();
        return vector<int>({array[ret.first], array[ret.second]});
    }
};

int main() {
    vector<int> v = {1, 2, 4, 7, 11, 15};
    vector<int> ret = Solution().FindNumbersWithSum(v, 15);
    for (auto r : ret) {
        cout << r << endl;
    }
    return 0;
}