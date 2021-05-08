#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/**
 * 题目：给定一个数组，找出其中最小的K个数。
 * 例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
 * 如果K>数组的长度，那么返回一个空的数组
 * 输入：[4,5,1,6,2,7,3,8],4    输出  [1,2,3,4]
 * 考点：数组
 * 分析：
 */

/**
 * 解法一：暴力法，数组排序
 * 时间复杂度：O(nlongn)
 */

class Solution {
   public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size() || k <= 0) {
            return {};
        }
        sort(input.begin(), input.end());
        return vector<int>({input.begin(), input.begin() + k});
    }
};

/**
 * 解法二：替换法。先定义一个容量为 k
 * 的数组A，填满并升序排序，之后每一个数与数组A[k-1]比较，
 * 大于则替换出并重新排序。
 * 时间复杂度：O(nlongk)
 */
class Solution2 {
   public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size() || k <= 0) {
            return {};
        }
        vector<int> ret(k);
        for (int i = 0; i < input.size(); i++) {
            if (i < k) {
                ret.push_back(input[i]);
            } else {
                if (input[i] < ret.back()) {
                    ret.pop_back();
                    ret.push_back(input[i]);
                    sort(ret.begin(), ret.end());
                }
            }
        }
        return ret;
    }
};

/**
 * 解法三：堆排序。思路和替换法类似，只不过用堆替代
 * 时间复杂度：O(nlongk)
 */
class Solution3 {
   public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size() || k <= 0) {
            return {};
        }
        vector<int> ret;
        priority_queue<int, vector<int>> queue;  // 由大到小排列
        for (auto v : input) {
            if (queue.size() < k) {
                queue.push(v);
            } else {
                if (v < queue.top()) {
                    queue.pop();
                    queue.push(v);
                }
            }
        }
        while (!queue.empty()) {
            ret.push_back(queue.top());
            queue.pop();
        }
        return ret;
    }
};

/**
 * 解法三：快排
 * 时间复杂度：O(n)
 */

int main() {
    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    vector<int> ret = Solution3().GetLeastNumbers_Solution(input, k);
    for (auto n : ret) {
        cout << n << endl;
    }
    return 0;
}