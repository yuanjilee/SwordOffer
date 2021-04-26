#include <iostream>
#include <stack>
using namespace std;
/**
 * 题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。队列中的元素为int类型。
 * 考点：栈。
 * 分析：栈是先进后出，队列是先进先出.push 栈和队列是一样的，pop 相反。
 */

/**
 * 解法一：
 * 最简单的思路是A栈用来存储数据，一个B栈用来作为中间容器，
 * 将所有元素从A弹出到B，最后一个出栈，再放回A保持与原顺序。
 * 优点简单直白，缺点每次pop一遍又将B放回到A。
 * 时间复杂度：Push O(1),Pop O(n)
 */

class Solution {
   public:
    void push(int node) { stack1.push(node); }

    int pop() {
        int pop;  // 返回弹出的值
        int size = stack1.size();
        for (int i = 0; i < size - 1; i++) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        pop = stack1.top();
        stack1.pop();
        int size2 = stack2.size();
        for (int i = 0; i < size2; i++) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return pop;
    }

   private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * 优化：
 * 每次B又重新放回A不妥，下次pop如果B中有元素(已经和队列顺序保持一致)应该直接从B中pop,
 * 如果没有则重复从A中放入B形成新的队列数据。
 * 时间复杂度：Push O(1),Pop O(1)
 */

class Solution2 {
   public:
    void push(int node) { stack1.push(node); }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int pop = stack2.top();  // 返回弹出的值
        stack2.pop();
        return pop;
    }

   private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution2 s = Solution2();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << endl;
    return 0;
}