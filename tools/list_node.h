// ListNode
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// return a pHead
ListNode* test_list_node();