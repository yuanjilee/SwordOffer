#include <iostream>
#include <map>

#include "../tools/tree_node.h"
using namespace std;
/**
 * 题目：输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
 * 平衡二叉树（Balanced Binary Tree），具有以下性质：
 * 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，
 * 并且左右两个子树都是一棵平衡二叉树。
 * 输入：{1,2,3,4,5,6,7}  输出 true
 * 考点：二叉树
 * 分析：
 */

/**
 * 解法一：求出高度，以及相应的左右树
 * 时间复杂度：
 */

class Solution {
   public:
    map<TreeNode*, int> m;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        depth(pRoot);
        return judge(pRoot);
    }

    int depth(TreeNode* root) {  // 每一个节点为根的数的高度
        if (!root) return 0;
        if (m.find(root) != m.end()) return m[root];
        int l = depth(root->left);
        int r = depth(root->right);
        return m[root] = max(l, r) + 1;
    }

    bool judge(TreeNode* root) {  // 判断左右是否相等或<= 1
        if (!root) return true;
        return abs(m[root->left] - m[root->right]) <= 1 && judge(root->left) &&
               judge(root->right);
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
    //  cout << Solution() << endl;
    return 0;
}