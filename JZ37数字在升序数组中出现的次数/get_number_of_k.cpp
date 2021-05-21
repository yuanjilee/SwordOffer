#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：统计一个数字在升序数组中出现的次数。
 * 输入：[1,2,3,3,3,3,4,5],3  输出 4
 * 考点：数组，二分
 * 分析：
 */

/**
 * 解法一：暴力法，遍历
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    int GetNumberOfK(vector<int> data, int k) {
        int ret = 0;
        for (int d : data) {
            if (d == k) {
                ret++;
            }
        }
        return ret;
    }
};

/**
 * 解法二：但是，这并没有用到题干的升序信息，所以还得优化。
 * 因为是升序有序数组，所以我们查找一个数可以使用二分法。
 * 时间复杂度：O(logn + k)
 */
class Solution2 {
   public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.size() == 0) {
            return 0;
        }
        int right = data.size() - 1;
        int left = 0;
        int mid = (right + left) / 2;
        ;
        while (data[mid] != k) {
            if (data[mid] > k) {
                right = mid;
            } else {
                left = mid + 1;
            }
            if (left >= right) {
                return 0;
            }

            mid = (right + left) / 2;

            // printf("🍉 min =%d, left = %d, right = %d, data[mid] = %d \n",
            // mid,
            //        left, right, data[mid]);
        }

        int ret = 0;
        for (int i = mid; i < data.size(); i++) {
            if (data[i] == k) {
                ret++;
            } else {
                break;
            }
        }
        for (int i = mid - 1; i >= 0; i--) {
            if (data[i] == k) {
                ret++;
            } else {
                break;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 3, 3, 3, 5, 6};
    cout << Solution2().GetNumberOfK(v, 3) << endl;
    return 0;
}