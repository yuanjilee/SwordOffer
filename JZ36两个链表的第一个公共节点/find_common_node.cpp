#include <iostream>
using namespace std;
/**
 * 题目：输入两个无环的单链表，找出它们的第一个公共结点。
 * （注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
 * 输入：listA = [4,1,8,4,5], listB = [5,0,1,8,4,5],  输出 8
 * 考点：链表
 * 分析：拼凑成长度一样的链表然后比较
 */

/**
 * 解法一：先将自己走完，然后回过头来走对方的，相当于路程相等 a+b = b+a
 * 时间复杂度：O(m+n)
 */

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if (p1 != p2) {
            p1 = (p1 ? p1->next : pHead2);
            p2 = (p2 ? p2->next : pHead2);
        }
        return p1;
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
    // cout << Solution() << endl;
    return 0;
}