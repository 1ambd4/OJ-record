#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

int sum_of_left_leaves(TreeNode *root)
{
    if (root == nullptr) return 0;

    int res = 0;
    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            if (cur->left != nullptr) {
                q.push(cur->left);
                if (cur->left->left == nullptr && cur->left->right == nullptr) {
                    res += cur->left->val;
                }
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }

    return res;
}

int main()
{
    vector<int> vec1 { 3, 9, 20, -1, -1, 15, 7 };
    TreeNode *tree1 = build_tree(vec1);
    cout << sum_of_left_leaves(tree1) << endl;
    return 0;
}
