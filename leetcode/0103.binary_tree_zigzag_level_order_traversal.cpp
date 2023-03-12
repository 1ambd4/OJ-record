#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

vector<vector<int>> zigzag_level_order(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);
    bool dir = true;
    TreeNode *cur = nullptr;

    while (!q.empty()) {
        int n = q.size();
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();

            if (dir) {
                tmp.push_back(cur->val);
            } else {
                tmp.insert(tmp.begin(), cur->val);
            }

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        res.push_back(tmp);
        dir = !dir;
    }

    return res;
}

int main()
{
    vector<int> nums1 {3,9,20,-1,-1,15,7};
    TreeNode *tree1 = build_tree(nums1);
    vector<vector<int>> res1 = zigzag_level_order(tree1);
    cout << res1 << endl;

    return 0;
}

