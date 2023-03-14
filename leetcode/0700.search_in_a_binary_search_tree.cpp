#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* search_bst(TreeNode *root, int val)
{
    if (root == nullptr) return nullptr;

    TreeNode *cur = root;
    while (cur != nullptr) {
        if (cur->val < val) {
            cur = cur->right;
        } else if (cur->val > val) {
            cur = cur->left;
        } else {
            break;
        }
    }

    if (cur == nullptr) return nullptr;

    return cur->val == val ? cur : nullptr;
}

TreeNode* _search_bst(TreeNode *root, int val)
{
    if (root == nullptr) return nullptr;

    if (val < root->val) {
        return search_bst(root->left, val);
    } else if (val > root->val) {
        return search_bst(root->right, val);
    }

    return root;
}

TreeNode* __search_bst(TreeNode *root, int val)
{
    if (root == nullptr) return nullptr;

    if (val < root->val) {
        return search_bst(root->left, val);
    } else if (val > root->val) {
        return search_bst(root->right, val);
    }

    return root;
}

int main()
{
    vector<int> vec1{4,2,7,1,3};
    TreeNode *tree1 = build_tree(vec1);
    TreeNode *res1 = search_bst(tree1, 2);
    traversal(res1);

    vector<int> vec2{4,2,7,3,1};
    TreeNode *tree2 = build_tree(vec2);
    TreeNode *res2 = search_bst(tree2, 5);
    traversal(res2);
    return 0;
}
