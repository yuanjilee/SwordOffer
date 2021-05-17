#include "list_node.h"

#include <iostream>

ListNode* test_list_node() {
    ListNode* pNode = new ListNode(1);
    pNode->next = NULL;
    ListNode* pHead1 = pNode;

    for (int i = 3; i <= 10; i = i + 2) {
        ListNode* pTemp = new ListNode(i);
        pNode->next = pTemp;
        pNode = pTemp;
    }
    return pHead1;
}
