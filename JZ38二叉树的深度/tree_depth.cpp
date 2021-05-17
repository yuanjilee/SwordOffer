#include <iostream>
#include <queue>

// #include "../工具类/tree_node.cpp"
#include "../工具类/tree_node.h"
using namespace std;
/**
 * 题目：输入一棵二叉树，求该树的深度。
 * 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
 * 最长路径的长度为树的深度。
 * 输入：{1,2,3,4,5,#,6,#,#,7}  输出 4
 * 考点：二叉树
 * 分析：
 */

/**
 * 解法一：分治，算出左边长度， 右边长度，取较大值,递归
 * 时间复杂度：0(n)
 */

class Solution {
   public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int lval = TreeDepth(pRoot->left);
        int rval = TreeDepth(pRoot->right);
        return max(lval, rval) + 1;
    }
};

/**
 * 解法二：存入队列并弹出
 * 时间复杂度：
 */
class Solution2 {
   public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int ret = 0;
        queue<TreeNode*> q;  // 用辅助队列来存节点
        q.push(pRoot);
        while (!q.empty()) {
            int s = q.size();
            while (s != 0) {  // 对队列中的每一个节点找到子节点
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                s--;
            }
            ret++;
        }
        return ret;
    }
};

int main() {
    int nums[] = {1, 2, 3};
    TreeNode* root = initBTree(nums, 3);
    cout << Solution().TreeDepth(root) << endl;
    return 0;
}

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