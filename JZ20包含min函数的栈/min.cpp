#include <iostream>
#include <stack>
using namespace std;
/**
 * 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数。
 * 在该栈中，调用 min、push 及 pop 函数的时间复杂度都是 O(1).
 * push(value)：将元素 value压入栈中
 * pop()：弹出栈顶的元素
 * top()：获得栈顶元素
 * min()：获得栈中的最小元素。
 * 输入：["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
 * 输出：-1,2,1,-1
 * 考点：栈
 * 分析：入栈出栈都是O(1)没有问题，但是min需要遍历，所以这里得考虑辅助空间。
 * 关于栈的题目很常见用到辅助栈。
 */

/**
 * 解法一：辅助栈
 * 时间复杂度：O(1)
 */

class Solution {
   public:
    stack<int> s1, s2;  // s1正常操作，s2做min辅助

    void push(int value) {
        s1.push(value);
        if (s2.empty() || s2.top() >= value) {
            s2.push(value);  // 栈顶为最小值
        } else {
            s2.push(s2.top());  // 保持栈数目一致，便于pop
        }
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() { return s1.top(); }
    int min() { return s2.top(); }
};

/**
 * 解法二：
 * 时间复杂度：
 */
class Solution2 {
   public:
};

int main() {
    Solution* s = new Solution();
    s->push(-1);
    s->push(2);
    cout << s->min() << endl;
    cout << s->top() << endl;
    s->pop();
    s->push(1);
    cout << s->top() << endl;
    cout << s->min() << endl;
    return 0;
}