#include <iostream>
#include <map>
#include <vector>
using namespace std;
/**
 * 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 * 考点：数组，哈希
 * 分析：超过一半是一个有意思的突破点
 */

/**
 * 解法一：暴力法，新建字典，出现的数字作为key，次数作为 value
 */

class Solution {
   public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 1) {
            return numbers[0];
        }
        map<int, int> map;
        int mid = numbers.size() / 2 - 1;  // 一半数
        for (int i = 0; i < numbers.size(); i++) {
            int index = numbers[i];
            if (map.find(index) ==
                map.end()) {  // 没找到key，则以i为key初始化value为次数0
                map[index] = 0;
            } else {
                map[index] = map[index] + 1;  // 找到，则值+1；
                if (map[index] > mid) {
                    return index;
                }
            }
        };
        return 0;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << Solution().MoreThanHalfNum_Solution(v) << endl;
    return 0;
}