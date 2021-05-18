#include <iostream>
#include <set>
#include <vector>
using namespace std;
/**
 * 题目：现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
 * 有如下规则：
 * 1. A为1，J为11，Q为12，K为13，A不能视为14
 * 2. 大、小王为 0，0可以看作任意牌
 * 3.
 * 如果给出的五张牌能组成顺子（即这五张牌是连续的）就输出true，否则就输出false。
 * 例如：给出数据[6,0,2,0,4]
 * 中间的两个0一个看作3，一个看作5 。即：[6,3,2,5,4]
 * 这样这五张牌在[2,6]区间连续，输出true
 * 数据保证每组5个数字，每组最多含有4个零，数组的数取值为 [0, 13]
 * 输入：[6,0,2,0,4] 输出 true
 * 考点：数组, set
 * 分析：判断最大值最小值之间的差以及是否有0
 */

/**
 * 解法一：set
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) {
            return false;
        }
        int num_zero = 0;
        set<int> s;
        int sub;
        int num_max = -1;
        int num_min = 14;
        for (int n : numbers) {
            if (n > 0) {
                if (s.count(n) > 0) {  // 除0外有重复，直接 false
                    return false;
                }
                s.insert(n);
                num_max = max(num_max, n);
                num_min = min(num_min, n);
            }
        }
        return num_max - num_min < 5;
    }
};

/**
 * 解法二：排序
 * 时间复杂度：
 */
class Solution2 {
   public:
};

int main() {
    vector<int> v = {1, 3, 2, 5, 4};
    cout << Solution().IsContinuous(v) << endl;
    return 0;
}