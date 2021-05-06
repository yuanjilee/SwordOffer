#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
 * 其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
 * 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
 * 输入: [1,2,3,4,5]
 * 输出: [120,60,40,30,24]
 * 考点：数组
 * 分析：遍历找关系
 */

/**
 * 解法一：暴力法，两个for.loop，排除当前下标
 * 时间复杂度：O(n^2)
 */

class Solution {
   public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> v(A.size(), 1);
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                if (i != j) {
                    v[i] *= A[j];
                }
            }
        }
        return v;
    }
};

/**
 * 解法二：我们可以将i的乘积组分为两部分i左侧和i右侧，分别计为 left[i],right[i],
 * left[i] = left[i-1]*A[i-1], rihgt[i] = right[i+1]*A[i+1],
 * 那么我们的任务转换为求 left 和 right.
 * 时间复杂度：O(n)
 */
class Solution2 {
   public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);
        for (int i = 1; i < A.size(); ++i) {
            B[i] = B[i - 1] * A[i - 1];  // left[i]用B[i]代替
        }
        int tmp = 1;
        for (int j = A.size() - 2; j >= 0;
             --j) {  // 算right需要知道后面的值，所以倒序计算
            tmp *= A[j + 1];  // right[i]用tmp代替
            B[j] *= tmp;
        }
        return B;
    }
};

int main() {
    vector<int> ret = Solution2().multiply({1, 2, 3, 4, 5});
    for (int i : ret) {
        cout << i << endl;
    }
    return 0;
}