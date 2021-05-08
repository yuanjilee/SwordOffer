#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
 * 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
 * 序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 * 输入：push [1,2,3,4,5], pop [4,3,5,1,2]  输出：false
 * 考点：栈
 * 分析：弹出的都会先入栈，所以用一个栈来存储。最后判断栈是否为空。
 */

/**
 * 解法一：O(n)
 * 时间复杂度：
 */

class Solution {
   public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() == 0) return false;
        stack<int> stack;
        for (int i = 0, j = 0; i < pushV.size(); i++) {
            stack.push(pushV[i]);
            while (
                j < popV.size() &&
                stack.top() ==
                    popV[j]) {  // 当栈顶元素等于popV中元素，则弹出并继续向后判断
                stack.pop();
                j++;
            }
        }
        return stack.empty();
    }
};

/**
 * 解法二：
 * 时间复杂度：
 */
class Solution2 {
   public:
};

int main() {
    vector<int> pushV = {1, 2, 3, 4, 5}, popV = {3, 5, 4, 2, 1};
    cout << Solution().IsPopOrder(pushV, popV) << endl;
    return 0;
}