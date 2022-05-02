#include <iostream>
#include <queue>

#include "leetcode.h"

using namespace std;

vector<int> right_side_view(TreeNode *root)
{
    vector<int> ret;

    if (root == nullptr) return ret;

    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }

        ret.push_back(cur->val);
    }

    return ret;
}

int main()
{
    vector<int> vec1 { 1, 2, 3, -1, 5, -1, 4 };
    TreeNode *tree1 = build_tree(vec1);
    vector<int> ret1 = right_side_view(tree1);
    cout << ret1 << endl;
    return 0;
}
