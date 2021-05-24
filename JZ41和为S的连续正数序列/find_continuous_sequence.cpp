#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,
 * 他马上就写出了正确答案是100。
 * 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
 * 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
 * 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 * 输入：9  输出：[[2,3,4],[4,5]]
 * 考点：穷举
 * 分析：
 */

/**
 * 解法一：遍历穷举
 * 时间复杂度：
 */

class Solution {
   public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        int cursor = 1;
        vector<vector<int>> ret;
        while (cursor <= (sum + 1) / 2) {
            int count = cursor;
            vector<int> tmp;
            tmp.push_back(cursor);
            for (int i = cursor + 1; i < sum; i++) {  // 上取整除
                tmp.push_back(i);
                count += i;
                if (count == sum) {
                    ret.push_back(tmp);
                    cursor++;
                    break;
                } else if (count > sum) {
                    cursor++;
                    break;
                }
            }
        }
        return ret;
    }
};

/**
 * 解法二：对解法一的优化，求区间，想滑动窗口
 * 时间复杂度：
 */
class Solution2 {
   public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        int l = 1, r = 1;
        int tmp = 0;
        while (l <= sum / 2) {
            if (tmp < sum) {  // 右边界滑动，扩大
                tmp += r;
                ++r;
            } else if (tmp > sum) {  // 左边界滑动，收缩
                tmp -= l;
                ++l;
            } else {  // 相等，得出区间，并左边界滑动，收缩为新区间继续求解
                vector<int> ans;
                for (int k = l; k < r; ++k) ans.push_back(k);
                ret.push_back(ans);
                tmp -= l;
                ++l;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> v = s.FindContinuousSequence(100);
    for (auto vv : v) {
        cout << "🍉\n" << endl;
        for (auto vvv : vv) {
            cout << vvv << endl;
        }
    }

    return 0;
}