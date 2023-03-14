#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* _insert_into_bst(TreeNode *root, int val)
{
    if (root == nullptr) return new TreeNode(val);

    TreeNode *cur = root, *pre = cur;
    while (cur != nullptr) {
        pre = cur;
        if (cur->val > val) {
            cur = cur->left;
        } else if (cur->val < val) {
            cur = cur->right;
        }
    }

    if (val < pre->val) pre->left = new TreeNode(val);
    else pre->right = new TreeNode(val);

    return root;
}

TreeNode* insert_into_bst(TreeNode *root, int val)
{
    if (root == nullptr) return new TreeNode(val);

    if (root->val < val) {
        root->right = insert_into_bst(root->right, val);
    } else if (root->val > val) {
        root->left = insert_into_bst(root->left, val);
    }

    return root;
}

int main()
{
    vector<int> nums1 {4,2,7,1,3};
    TreeNode *tree1 = build_bst(nums1);
    TreeNode *res1 = _insert_into_bst(tree1, 5);
    traverse_bst(res1);

    return 0;
}

