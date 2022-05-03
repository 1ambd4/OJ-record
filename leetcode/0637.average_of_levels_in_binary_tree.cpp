#include <iostream>
#include <queue>

#include "leetcode.h"

using namespace std;

void bfs(TreeNode *root, vector<double>& ret)
{
    if (root == nullptr) return ;

    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();

        double sum = 0;

        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();

            sum += cur->val;

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }

        ret.push_back(sum/size);
    }
}

void dfs(TreeNode *root, int& level, vector<int>& cnt, vector<long long>& sum)
{
    if (root == nullptr) return ;

    if (level < cnt.size()) {
        ++cnt[level];
        sum[level] += root->val;
    } else {
        cnt.push_back(1);
        sum.push_back(root->val);
    }
    ++level;
    dfs(root->left, level, cnt, sum);
    dfs(root->right, level, cnt, sum);
    --level;
}

vector<double> average_of_levels(TreeNode *root)
{
    vector<double> ret;
    // bfs(root, ret);
    int level = 0;
    vector<int> cnt;
    vector<long long> sum;
    dfs(root, level, cnt, sum);
    for (int i = 0; i < cnt.size(); ++i) {
        ret.push_back((double)sum[i]/cnt[i]);
    }
    return ret;
}

int main()
{
    vector<int> vec1 { 3, 9, 20, -1, -1, 15, 7 };
    TreeNode *tree1 = build_tree(vec1);
    vector<double> ret1 = average_of_levels(tree1);
    cout << ret1 << endl;

    vector<int> vec2 { 3, 1, 5, 0, 2, 4, 6 };
    TreeNode *tree2 = build_tree(vec2);
    vector<double> ret2 = average_of_levels(tree2);
    cout << ret2 << endl;
    return 0;
}
