#include <iostream>
using namespace std;
/**
 * 题目：输入两个单调递增的链表，输出两个链表合成后的链表，
 * 当然我们需要合成后的链表满足单调不减规则。
 * 考点：链表
 * 分析：对两个链表排序，我们可以新建一个链表用于接收合并后的数据
 */

/**
 * 解法一：非递归
 * temp 用来移动新链表，而temp会随着合并next会一直移动最后，所以再建一个
 * root 用于返回新链表的头
 */

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* temp = new ListNode(-1);  // 游标节点
        ListNode* root = temp;              // 待返回的头节点
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                temp->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                temp->next = pHead2;
                pHead2 = pHead2->next;
            }
            temp = temp->next;
        }
        if (pHead1 == NULL) {
            temp->next = pHead2;
        }
        if (pHead2 == NULL) {
            temp->next = pHead1;
        }
        return root->next;
    }
};

int main() {
    int n;
    Solution s = Solution();

    ListNode* pNode = new ListNode(1);
    pNode->next = NULL;
    ListNode* pHead1 = pNode;

    for (int i = 3; i <= 10; i = i + 2) {
        ListNode* pTemp = new ListNode(i);
        pNode->next = pTemp;
        pNode = pTemp;
    }

    ListNode* pNode2 = new ListNode(2);
    pNode2->next = NULL;
    ListNode* pHead2 = pNode2;

    for (int i = 4; i <= 10; i = i + 2) {
        ListNode* pTemp = new ListNode(i);
        pNode2->next = pTemp;
        pNode2 = pTemp;
    }

    ListNode* head = s.Merge(pHead1, pHead2);
    while (pHead1) {
        cout << pHead1->val << endl;
        pHead1 = pHead1->next;
    }
    return 0;
}