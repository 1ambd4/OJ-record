#include <iostream>
#include <queue>

#include "leetcode.h"

using namespace std;

vector<vector<int>> level_order(TreeNode* root)
{
    vector<vector<int>> ret;

    if (root == nullptr) return ret;

    queue<TreeNode*> q;
    TreeNode *cur;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        // vector<int> tmp;
        ret.push_back(vector<int>());

        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);

            // tmp.push_back(cur->val);
            ret.back().push_back(cur->val);
        }

        // ret.push_back(tmp);
    }

    return ret;
}

int main()
{
    vector<int> vec1 { 3, 9, 20, -1, -1, 15, 7 };
    TreeNode *tree1 = build_tree(vec1);
    traversal(tree1);
    vector<vector<int>> res1 = level_order(tree1);
    cout << res1 << endl;
    return 0;
}
