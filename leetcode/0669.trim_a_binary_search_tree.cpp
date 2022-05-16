#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// 删除bst中小于low和大于high的节点
TreeNode* trim_bst(TreeNode *root, int low, int high)
{
    if (root == nullptr) return nullptr;

    // 根节点小于low，则左子树必然小于low，直接返回右子树修建后的结果
    if (root->val < low) {
        return trim_bst(root->right, low, high);
    }
    // 根节点大于high，则右子树必然大于high，直接返回左子树修建后的结果
    if (root->val > high) {
        return trim_bst(root->left, low, high);
    }

    root->left = trim_bst(root->left, low, high);
    root->right = trim_bst(root->right, low, high);

    return root;
}

int main()
{
    vector<int> vec1 { 1, 0, 2 };
    TreeNode *tree1 = build_tree(vec1);
    TreeNode *res1 = trim_bst(tree1, 1, 2);
    traversal(res1);
    return 0;
}
