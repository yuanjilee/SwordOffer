#include <iostream>
#include <stack>

#include "../工具类/list_node.h"
using namespace std;
/**
 * 题目：输入一个链表，反转链表后，输出新链表的表头。
 * 输入：{1,2,3}  输出 {3,2,1}
 * 考点：
 * 分析：
 */

/**
 * 解法一：遍历将所有节点存在一个数组/栈中，然后出栈为一个新的链表
 * 时间复杂度：
 */

class Solution {
   public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return nullptr;
        stack<ListNode*> s;
        while (pHead) {
            s.push(pHead);
            pHead = pHead->next;
        }
        ListNode* head = s.top();
        ListNode* reversedList = head;
        s.pop();
        while (!s.empty()) {
            // printf("%d \n", reversedList->val);
            reversedList->next = s.top();
            reversedList = reversedList->next;
            s.pop();
        }
        reversedList->next = nullptr;
        return head;
    }
};

/**
 * 解法二：三个指针实现反转链表
 * head: 翻转头的头，初始化为 nullptr
 * cur: 当前游标 初始化为 pHead
 * tmp: 临时指针，保存后续链表，初始化 nullptr
 * 时间复杂度：
 */
class Solution2 {
   public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return nullptr;
        ListNode* head = nullptr;
        ListNode* cur = pHead;
        ListNode* tmp = nullptr;
        while (cur) {
            tmp = cur->next;   // 进一步，保存链表
            cur->next = head;  // cur->next 断开并重新指向 head
            head = cur;        // head 切换到 cur 的位置
            cur = tmp;         // 切换到保存的链表继续后移
        }
        return head;
    }
};

int main() {
    ListNode* pNode = new ListNode(1);
    pNode->next = NULL;
    ListNode* pHead1 = pNode;

    for (int i = 3; i <= 10; i = i + 2) {
        ListNode* pTemp = new ListNode(i);
        pNode->next = pTemp;
        pNode = pTemp;
    }

    cout << Solution2().ReverseList(pHead1)->val << endl;
    return 0;
}