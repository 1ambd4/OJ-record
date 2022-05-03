#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

void bfs(TreeNode *root, vector<int>& res)
{
    if (root == nullptr) return ;

    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    q.push(root);
    while (!q.empty()) {
        int size = q.size(), tmp = q.front()->val;

        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            tmp = max(tmp, cur->val);
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }

        res.push_back(tmp);
    }
}

void dfs(TreeNode *root, vector<int>& res, int level)
{
    if (root == nullptr) return ;

    if (level < res.size()) {
        res[level] = max(res[level], root->val);
    } else {
        res.push_back(root->val);
    }
    ++level;
    dfs(root->left, res, level);
    dfs(root->right, res, level);
    --level;
}

vector<int> largest_values(TreeNode *root)
{
    vector<int> res;
    // bfs(root, res);
    dfs(root, res, 0);
    return res;
}

int main()
{
    vector<int> vec1 { 1, 3, 2, 5, 3, -1, 9 };
    TreeNode *tree1 = build_tree(vec1);
    vector<int> res1 = largest_values(tree1);
    cout << res1 << endl;
    return 0;
}
