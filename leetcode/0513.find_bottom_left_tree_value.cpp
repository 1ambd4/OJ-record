#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

int _find_bottom_left_value(TreeNode *root)
{
    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    int res = root->val, lvl = 0, level = 0;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        ++level;
        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            if (cur->left != nullptr) {
                q.push(cur->left);
                if (cur->left->left == cur->left->right && level > lvl) {
                    res = cur->left->val;
                    lvl = level;
                }
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
                if (cur->right->left == cur->right->right && level > lvl) {
                    res = cur->right->val;
                    lvl = level;
                }
            }
        }
    }
    return res;
}

void traverse(TreeNode *root, int& res, int depth, int& max_depth)
{
    if (root == nullptr) return ;

    ++depth;
    if (depth > max_depth) {
        max_depth = depth;
        res = root->val;
    }
    traverse(root->left, res, depth, max_depth);
    traverse(root->right, res, depth, max_depth);
    --depth;
}

int __find_bottom_left_value(TreeNode *root)
{
    int res = root->val, max_depth = 0;
    traverse(root, res, 0, max_depth);
    return res;
}

int find_bottom_left_value(TreeNode *root)
{
    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    q.push(root);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->right != nullptr) q.push(cur->right);
        if (cur->left != nullptr) q.push(cur->left);
    }
    return cur->val;
}

int main()
{
    vector<int> vec1 { 1, 2, 3, 4, -1, 5, 6, -1, -1, 7 };
    TreeNode *tree1 = build_tree(vec1);
    cout << find_bottom_left_value(tree1) << endl;
    return 0;
}
