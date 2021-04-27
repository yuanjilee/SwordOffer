#include <iostream>
#include <vector>
using namespace std;
/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * 考点：二分法。
 * 分析：既然是非递减排序的序列，则两两比较知道遇到后一个小于前一个则返回
 */

/**
 * 解法一：暴力法，直接遍历一遍数组
 * 优点简单直白，缺点没有用上题干
 * 时间复杂度：0(n)
 */

class Solution {
   public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }
        int k = rotateArray[0];
        for (int i = 1; i < rotateArray.size(); i++) {
            if (k <= rotateArray[i]) {
                k = rotateArray[i];
            } else {
                return rotateArray[i];
            }
        }
        return 0;
    }
};

/**
 * 解法二：二分法（夹逼法），因为是整体移到后面的，所以提取arr[mid]来与一个端点比较，
 * 因为是非递减的旋转找最小值，所以与右端点比较。
 * 优点简单直白
 * 时间复杂度：O(longN)
 */

class Solution2 {
   public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }
        int first = 0, last = rotateArray.size() - 1;
        while (first < last) {  // 夹逼
            if (rotateArray[first] <
                rotateArray[last]) {  // 直接返回 [1, 2, 3, 4, 5]
                return rotateArray[first];
            }
            int mid = first + (last - first) / 2;
            if (rotateArray[mid] >
                rotateArray[last]) {  // 结果在右侧 [5,6,7,2,3]
                first = mid + 1;
            } else if (rotateArray[mid] <
                       rotateArray[last]) {  // 结果在左侧 [5,6,1,2,3]
                last = mid;
            } else {  //丢掉相等值继续比较 [2, 2, 2, 2, 0, 1, 2]
                --last;
            }
        }
        return rotateArray[first];
    }
};

int main() {
    vector<int> v = {5, 6, 7, 1, 2};
    cout << Solution2().minNumberInRotateArray(v) << endl;
}