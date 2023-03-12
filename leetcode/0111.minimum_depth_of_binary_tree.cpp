#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.h"

using namespace std;


int minimum_depth(TreeNode *root)
{
    int depth = 0;
    if (root == nullptr) return depth;

    queue<TreeNode*> q;
    q.push(root);
    TreeNode *cur = nullptr;

    while (!q.empty()) {
        int n = q.size();
        ++depth;
        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();

            // 我太蠢啦
            // if (root->left == nullptr && root->right == nullptr) {
            // if (cur->left == nullptr && cur->right == nullptr) {
            if (cur->left == cur->right) {
                return depth;
            }

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
    }

    return -1;
}


// 层次遍历（BFS）
// 错误写法（笑死，以前好蠢啊我
int __minimum_depth(TreeNode *root)
{
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int ans = 1;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left == nullptr && cur->right == nullptr) {
            return ans;
        }
        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
        }
        ans++;
    }
}

int _minimum_depth(TreeNode *root)
{
    if (root == nullptr)  return 0;
    queue<TreeNode*> q;
    q.push(root);
    int ans = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left == nullptr && cur->right == nullptr) {
                return ans;
            }
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        ans++;
    }

    return -1;
}

int main()
{
    vector<int> nums1 { 3, 9, 20, -1, -1, 15, 7 };
    TreeNode *case1 = build_tree(nums1);
    // traversal(case1);
    cout << minimum_depth(case1) << endl;

    vector<int> nums2 { 2, -1, 3, -1, 4, -1, 5, -1, 6 };
    TreeNode *case2 = build_tree(nums2);
    // traversal(case2);
    cout << minimum_depth(case2) << endl;

    vector<int> nums3 { 1, 2, 3, 4, 5 };
    TreeNode *case3 = build_tree(nums3);
    // traversal(case3);
    cout << minimum_depth(case3) << endl;
    return 0;
}
