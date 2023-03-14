#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* delete_node(TreeNode *root, int key)
{
    if (root == nullptr) return nullptr;

    if (root->val == key) {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;

        TreeNode *min = root->right;
        while (min->left != nullptr) min = min->left;

        root->right = delete_node(root->right, min->val);
        min->left = root->left;
        min->right = root->right;
        root = min;
    } else if (root->val < key) {
        root->right = delete_node(root->right, key);
    } else if (root->val > key) {
        root->left = delete_node(root->left, key);
    }

    return root;
}


TreeNode* _delete_node(TreeNode *root, int key)
{
    if (root == nullptr) return nullptr;

    TreeNode *cur = root, *pre = root;

    while (cur != nullptr) {
        if (cur->val > key) {
            pre = cur;
            cur = cur->left;
        } else if (cur->val < key) {
            pre = cur;
            cur = cur->right;
        } else {
            break;
        }
    }

    if (cur == nullptr) return root;

    // 未解决待删节点为根节点的情况
    bool dir = (pre->left == cur ? true : false);

    if (cur->left == nullptr && cur->right == nullptr) {
        if (dir) pre->left = nullptr;
        else pre->right = nullptr;
    } else if (cur->left == nullptr && cur->right != nullptr) {
        if (dir) pre->left = cur->right;
        else pre->right = cur->right;
    } else if (cur->left != nullptr && cur->right == nullptr) {
        if (dir) pre->left = cur->left;
        else pre->right = cur->left;
    } else {
        TreeNode *tmp = cur;
        while (tmp->left != nullptr) tmp = tmp->left;
        tmp->right = cur->right;
        if (dir) pre->left = tmp;
        else pre->right = tmp;
    }


    return root;
}

int main()
{
    vector<int> nums1 {5,3,6,2,4,-1,7};
    TreeNode *tree1 = build_tree(nums1);
    TreeNode *res1 = _delete_node(tree1, 3);
    traversal(res1);

    vector<int> nums2 {};
    TreeNode *tree2 = build_tree(nums2);
    TreeNode *res2 = _delete_node(tree2, 0);
    traversal(res2);

    vector<int> nums3 {0};
    TreeNode *tree3 = build_tree(nums3);
    TreeNode *res3 = _delete_node(tree3, 0);
    traversal(res3);

    return 0;
}

