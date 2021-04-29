#include <iostream>
#include <map>
#include <vector>
using namespace std;
/**
 * 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 * 考点：数组，排序，哈希
 * 分析：超过一半是一个有意思的突破点
 */

/**
 * 解法一：暴力法，新建字典，出现的数字作为key，次数作为 value
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 1) {
            return numbers[0];
        }
        map<int, int> map;
        int mid = numbers.size() / 2;  // 整除，一半数
        for (const int val : numbers) {
            map[val]++;
            if (map[val] > mid) {
                return val;
            }
        };
        return 0;
    }
};

/**
 * 解法二：利用题干，因为出现次数超过一半,所以可以采用“同归于尽”法，
 * 遇到不同数字（敌人）相互死亡，遇到相同数字（友军）计数+1。
 */
class Solution2 {
   public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 1) {
            return numbers[0];
        }
        int soldier = numbers[0];  // 标记当前数
        int count = 1;             // 标记当前数次数
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] != soldier) {
                if (count == 1) {  // 如果当前数只出现一次，则同归于尽
                    i++;
                    soldier = numbers[i];
                } else {
                    count--;
                }
            } else {
                count++;
            }
        }
        // 检查
        count = 0;
        for (const int k : numbers) {
            if (soldier == k) count++;
        }
        if (count > numbers.size() / 2) return soldier;
        return 0;
    }
};

int main() {
    vector<int> v = {3, 1, 3, 2, 3, 5, 3};
    cout << Solution2().MoreThanHalfNum_Solution(v) << endl;
    return 0;
}