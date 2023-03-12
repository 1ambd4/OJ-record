#include <iostream>

#include "leetcode.h"

using namespace std;

TreeNode* invert_tree(TreeNode *root)
{
    if (root == nullptr) return nullptr;

    // 对当前情况的处理放到前序或者后序位置均可
    // 形式上相近，思想上却相去甚远
    // 前序位置是自顶向下的
    // 而后序位置是自底向上的

    // swap(root->left, root->right);

    invert_tree(root->left);
    invert_tree(root->right);

    swap(root->left, root->right);

    return root;
}

TreeNode* _invert_tree(TreeNode* root)
{
    // base case
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invert_tree(root->left);
    invert_tree(root->right);

    return root;
}

int main()
{
    vector<int> vec1 {4,2,7,1,3,6,9};
    TreeNode *tree1 = build_tree(vec1);
    TreeNode *res1 = invert_tree(tree1);
    traversal(res1);

    vector<int> vec2 {2,1,3};
    TreeNode *tree2 = build_tree(vec2);
    TreeNode *res2 = invert_tree(tree2);
    traversal(res2);

    vector<int> vec3 {};
    TreeNode *tree3 = build_tree(vec3);
    TreeNode *res3 = invert_tree(tree3);
    traversal(res3);
    return 0;
}
