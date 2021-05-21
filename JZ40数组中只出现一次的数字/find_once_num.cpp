#include <iostream>
#include <map>
#include <vector>
using namespace std;
/**
 * 题目：一个整型数组里除了两个数字只出现一次，其他的数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。
 * 输入：[1,4,1,6]  输出：[4,6]
 * 考点：数组，哈希，位运算
 * 分析：
 */

/**
 * 解法一：用 map 来记录数字以及出现的次数
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        map<int, int> map;
        for (auto a : array) {
            map[a]++;
        }
        vector<int> ret;
        for (auto m : map) {
            if (m.second == 1) {
                ret.push_back(m.first);
            }
            if (ret.size() == 2) {
                break;
            }
        }
        if (ret[0] > ret[1]) swap(ret[0], ret[1]);
        return ret;
    }
};

/**
 * 解法二：异或：时间复杂度为O(n),空间复杂度为O(1)
 * 异或概念：对数组中所有数组进行异或（^）,异或异或是强调异，即相同为0,不同为1。
 * 设a，b为任意两个数。相同两数异或为0(a^a =
 * 0)，0与任何一个数异或为该数本身(a^0=a)。且异或符合交换律（a^b=b^a）。
 * 所以题目中数组所有数字异或后结果为两个不同的数进行异或。（设为a^b）
 * 异或后，从后往前，找到他们二进制中第一个为1的位置，该位置上两个数的二进制不一样否则不可能为1.（设该位置为k）为了划分出来两个数。
 * 然后重新对数组异或，但是在异或的时候，根据该位置（k上为1和0）来划分，最后会将这两数字划分开来。虽然其它的数也会划分开来，但是它们是成对划分的，无论在哪边都不影响最后结果。
 * 时间复杂度：O(n)
 */
class Solution2 {
   public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int> ans(2);
        int res = 0;
        for (int x : array) {
            res ^= x;
        }
        int m = 1;
        while (!(m & res))
            m <<= 1;  // 找到二进制上第一个1，该位置上两数二进制不同
        for (int x : array) {
            if (!(m & x))
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }
        if (ans[0] > ans[1]) swap(ans[0], ans[1]);
        return ans;
    }
};

int main() {
    vector<int> v = {1, 4, 1, 6};
    v = Solution2().FindNumsAppearOnce(v);
    for (auto i : v) {
        cout << i << endl;
    }
    return 0;
}