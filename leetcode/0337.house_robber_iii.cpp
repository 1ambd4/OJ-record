#include <iostream>
#include <vector>
#include <unordered_map>

#include "leetcode.h"

using namespace std;

// 加上记忆化搜索
int _rob(TreeNode *root)
{
    unordered_map<TreeNode*, int> memo;
    // int res = 0;

    auto traverse = [&memo](auto&& self, TreeNode *root) -> int {
        if (root == nullptr) return 0;
        if (memo.contains(root)) return memo[root];

        int res = root->val;

        if (root->left != nullptr) {
            res += (self(self, root->left->left) + self(self, root->left->right));
        }
        if (root->right != nullptr) {
            res += (self(self, root->right->left) + self(self, root->right->right));
        }

        res = max(res, self(self, root->left) + self(self, root->right));
        memo[root] = res;

        return res;
    };

    return traverse(traverse, root);
}

// 偷上瘾了是吧
int __rob(TreeNode *root)
{
    if (root == nullptr) return 0;

    int res = root->val;
    if (root->left != nullptr) {
        res += (rob(root->left->left) + rob(root->left->right));
    }
    if (root->right != nullptr) {
        res += (rob(root->right->left) + rob(root->right->right));
    }

    return max(res, rob(root->left) + rob(root->right));
}

// int rob(TreeNode *root)
// {
//     int res = 0;
//     auto traverse = [&res](TreeNode *root) -> int {
//         if (root == nullptr) return 0;
//
//         // 左右子树为空了，那么直接选呗
//         if (root->left == root->right) return root->val;
//
//         if (root->left != nullptr && root->right != nullptr) {
//             return max(root->val + traverse(root->left->left) + traverse(root->left->right) + traverse(root->right->left) + traverse(root->right->right), traverse(root->left) + traverse(root->right));
//         } else if (root->left != nullptr) {
//             return max(root->val + traverse(root->left->left) + traverse(root->left->right),
//         } else if (root->right != nullptr) {
//         }
//     };
//
//     return res;
// }

int main()
{
    vector<int> nums1 {3,2,3,-1,3,-1,1};
    TreeNode *tree1 = build_tree(nums1);
    cout << rob(tree1) << endl;

    vector<int> nums2 {3,4,5,1,3,-1,1};
    TreeNode *tree2 = build_tree(nums2);
    cout << rob(tree2) << endl;

    return 0;
}

