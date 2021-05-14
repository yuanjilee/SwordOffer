#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：输入一个链表，输出该链表中倒数第k个结点。
 * 如果该链表长度小于k，请返回空。
 * 输入：{1,2,3,4,5},1   输出 {5}
 * 考点：链表
 * 分析：
 */

/**
 * 解法一：将所有节点存在数组/栈中，然后输出相应下标
 * 时间复杂度：O(n)
 */

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        vector<ListNode*> v;
        while (pHead) {
            v.push_back(pHead);
            pHead = pHead->next;
        }
        if (k > v.size()) {
            return NULL;
        }
        return v[v.size() - k];
    }
};

/**
 * 解法二：双指针法，第一个指针先走k步，然后第二个指针从头走，两个一起走，
 * 当第一个指针到达末尾，返回第二个指针的位置。
 * 时间复杂度：O(k+n)
 */
class Solution2 {
   public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode* pTmp = pHead;
        while (k > 0) {
            if (pHead == nullptr) {
                return nullptr;
            }
            pHead = pHead->next;
            k--;
        }
        while (pHead) {
            pHead = pHead->next;
            pTmp = pTmp->next;
        }

        return pTmp;
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
    ListNode* findNode = Solution2().FindKthToTail(pHead1, 5);
    cout << findNode->val << endl;
    return 0;
}