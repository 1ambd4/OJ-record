#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

int deepest_sum(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *cur = nullptr;
    int n = 0, sum = 0;

    while (!q.empty()) {
        n = q.size(), sum = 0;

        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();
            sum += cur->val;
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
    }

    return sum;
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, 8 };
    TreeNode *tree1 = build_tree(nums1);
    cout << deepest_sum(tree1) << endl;

    vector<int> nums2 { 6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5 };
    TreeNode *tree2 = build_tree(nums2);
    cout << deepest_sum(tree2) << endl;
    return 0;
}
