#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/**
 * 题目：给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。
 * 输入：{5,3,7,2,4,6,8},3     输出 {4}
 * 考点：二叉树遍历
 * 分析：这个题思路很简单，要排序必须遍历二叉树，然后放入数组再排序
 */

/**
 * 解法一：递归遍历，数组排序
 * 时间复杂度：递归：O(logn)  非递归： O(n)
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        vector<TreeNode*> v;
        order(pRoot, v);
        sort(v.begin(), v.end(), ascending);
        return v[k - 1];
    }

   private:
    // 升序
    static bool ascending(TreeNode* a, TreeNode* b) {
        return (a->val < b->val);
    }

    // 递归遍历存为数组
    void preOrder(TreeNode* root, vector<TreeNode*>& v) {
        if (root) {
            v.push_back(root);
            preOrder(root->left, v);
            preOrder(root->right, v);
        }
    }

    // 非递归遍历
    void order(TreeNode* pRoot, vector<TreeNode*>& num) {
        stack<TreeNode*> s;  //辅助栈
        TreeNode* pNode = pRoot;
        while (pNode) {
            s.push(pNode);
            num.push_back(pNode);  //保存节点
            pNode = pNode->left;   //往左子树转移
        }

        while (!s.empty()) {
            TreeNode* tempNode = s.top();  //取当前栈顶元素
            s.pop();
            if (tempNode->right)  //如果有右子树
            {
                TreeNode* t = tempNode->right;
                while (t) {
                    num.push_back(t);  //保存当前节点右子树
                    s.push(t);
                    t = t->left;  //往左子树转移
                }
            }
        }
    }
};

/**
 * 解法二：
 * 时间复杂度：
 */
class Solution2 {
   public:
    int m;
    TreeNode* ans;
    void dfs(TreeNode* p) {
        if (!p || m < 1) return;  //不满足条件直接返回NULL/每次递归出口：
        dfs(p->left);  //走到了最左边结点,到空不继续递归，该节点左右走完了回溯上一层
        if (m == 1) ans = p;  //最左边结点 / m-到1的时候，当前结点就是第m小
        if (--m > 0)
            dfs(p->right);  // 右子树同样处理/遍历该节点的右节点 (左中右)
    }
    TreeNode* KthNode(TreeNode* p, unsigned int k) {
        ans = NULL;
        m = k;  //初始化 ans=NULL 不满足条件返回NULL
        dfs(p);
        return ans;
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

int main() {
    int nums[] = {5, 3, 7, 2, 4, 6, 8};
    TreeNode* root = initBTree(nums, 7);

    TreeNode* ret = Solution().KthNode(root, 3);
    cout << ret->val << endl;
    return 0;
}