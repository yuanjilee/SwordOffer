#include "tree_node.h"

#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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