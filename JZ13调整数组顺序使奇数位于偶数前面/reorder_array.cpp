#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * 输入：[2,4,6,5,7]  输出  [5,7,2,4,6]
 * 考点：数组
 * 分析：
 */

/**
 * 解法一：暴力法，拿出两个数组分别存奇偶，然后合并
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    vector<int> reOrderArray(vector<int>& array) {
        if (array.size() <= 1) {
            return array;
        }
        vector<int> v1, v2, ret;
        for (auto a : array) {
            if (a % 2 != 0) {
                v1.push_back(a);
            } else {
                v2.push_back(a);
            }
        }
        ret.reserve(v1.size() + v2.size());  // preallocate memory
        ret.insert(ret.end(), v1.begin(), v1.end());
        ret.insert(ret.end(), v2.begin(), v2.end());
        return ret;
    }
};

/**
 * 解法二：一个数组，遇到奇数前置，并标记位置
 * 时间复杂度：O(n)
 */
class Solution2 {
   public:
    vector<int> reOrderArray(vector<int>& array) {
        int size = array.size();
        int index = 0;
        if (size <= 1) {
            return array;
        }
        for (int i = 0; i < size; i++) {
            if (array[i] % 2 != 0) {  // 奇数
                int tmp = array[i];
                array.erase(array.begin() + i);
                array.insert(array.begin() + index, tmp);
                index++;
            }
        }
        return array;
    }
};

int main() {
    vector<int> v = {2, 4, 6, 5, 7};
    vector<int> ret = Solution2().reOrderArray(v);
    for (auto r : ret) {
        cout << r << endl;
    }
    return 0;
}