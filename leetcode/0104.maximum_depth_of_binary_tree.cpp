#include <iostream>
#include <queue>

#include "leetcode.h"

using namespace std;

// 动态规划（自底向上）
int max_depth(TreeNode *root)
{
    if (root == nullptr) return 0;

    int left = max_depth(root->left);
    int right = max_depth(root->right);

    return 1 + max(left, right);
}

// 回溯（自顶向下）
void traverse(TreeNode *root, int depth, int &res)
{
    if (root == nullptr) {
        res = max(res, depth);
        return ;
    }

    ++depth;
    traverse(root->left, depth, res);
    traverse(root->right, depth, res);
    --depth;
}

int _max_depth(TreeNode* root)
{
    int res = 0, depth = 0;
    traverse(root, depth, res);
    return res;
}


// 层次遍历
int __max_depth(TreeNode *root)
{
    int res = 0;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);
    TreeNode *cur = nullptr;

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        ++res;
    }

    return res;
}

// int maxDepth(TreeNode *root)
// {
//     if (root == nullptr) {
//         return 0;
//     }
//     return max(maxDepth(root->left), maxDepth(root->right)) + 1;
// }

// 回溯
void _traverse(TreeNode *root, int& depth, int& res)
{
    if (root == nullptr) {
        res = max(depth, res);
        return;
    }

    ++depth;
    traverse(root->left, depth, res);
    traverse(root->right, depth, res);
    --depth;
}
int maxDepth(TreeNode *root)
{
    int depth = 0, res = 0;
    traverse(root, depth, res);
    return res;
}

int main()
{
    vector<int> case1 {3, 9, 20, -1, -1, 15, 7};
    TreeNode *tree1 = build_tree(case1);
    cout << max_depth(tree1) << endl;
    return 0;
}
