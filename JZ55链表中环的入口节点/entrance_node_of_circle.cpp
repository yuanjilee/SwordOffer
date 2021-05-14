#include <iostream>
#include <unordered_set>

#include "../工具类/list_node.h"
using namespace std;
/**
 * 题目：给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 * 输入：
 * 考点：
 * 分析：何为环，表示某一个节点的next指向了当前链表已有的节点
 */

/**
 * 解法一：遍历放入set，判断
 * 时间复杂度：
 */

class Solution {
   public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        unordered_set<ListNode*> s;
        while (pHead) {
            if (s.find(pHead) == s.end()) {
                s.insert(pHead);
                pHead = pHead->next;
            } else {
                return pHead;
            }
        }
        return nullptr;
    }
};

/**
 * 解法二：快慢指针法（类比操场跑圈）
 * 时间复杂度：
 */
class Solution2 {
   public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while (fast && fast->next) {
            fast = fast->next->next;  // 走两步
            slow = slow->next;        // 走一步
            if (fast == slow) break;
        }
        if (!fast || !fast->next) return nullptr;
        fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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

    pNode->next = pHead1->next->next;  // 1->3->5->7->9->5

    cout << Solution2().EntryNodeOfLoop(pHead1)->val << endl;
    return 0;
}