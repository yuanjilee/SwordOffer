#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/**
 * 题目：操作给定的二叉树，将其变换为源二叉树的镜像。
 * 比如：    源二叉树
            8
           /  \
          6   10
         / \  / \
        5  7 9 11
        镜像二叉树
            8
           /  \
          10   6
         / \  / \
        11 9 7  5
 * 考点：二叉树
 * 分析：遇到树，想递归
 */

/**
 * 解法一：递归
 * pRoot->lft  与 pRoot->right 交换，然后递归左右。
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (pRoot == NULL) return pRoot;  // 结束条件
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};

// Test

TreeNode* initBTree(int elements[], int size) {
    if (size < 1) {
        return NULL;
    }
    //动态申请size大小的指针数组
    TreeNode** nodes = new TreeNode*[size];
    //将int数据转换为TreeNode节点
    for (int i = 0; i < size; i++) {
        if (elements[i] == 0) {
            nodes[i] = NULL;
        } else {
            nodes[i] = new TreeNode(elements[i]);
        }
    }
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(nodes[0]);

    TreeNode* node;
    int index = 1;
    while (index < size) {
        node = nodeQueue.front();
        nodeQueue.pop();
        nodeQueue.push(nodes[index++]);
        node->left = nodeQueue.back();
        nodeQueue.push(nodes[index++]);
        node->right = nodeQueue.back();
    }
    return nodes[0];
}

void preOrder(TreeNode* root, vector<int>& result) {
    if (root) {
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}

void inOrder(TreeNode* root, vector<int>& result) {
    if (root) {
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
}

void postOrder(TreeNode* root, vector<int>& result) {
    if (root) {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
}

void traverse(vector<int> nums) {
    vector<int>::size_type size = nums.size();
    for (size_t i = 0; i < size; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

int main() {
    int n;
    Solution s = Solution();

    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    /** 源二叉树
            1
           /  \
          2    3
         / \  / \
        4  5  6  7

        镜像
            1
           /  \
          3    2
         / \  / \
        7  6  5  4
    */
    TreeNode* root = initBTree(nums, 7);
    TreeNode* head = s.Mirror(root);

    vector<int> preResult;
    preOrder(root, preResult);
    cout << "镜像后结果：" << '\n';
    traverse(preResult);
    return 0;
}