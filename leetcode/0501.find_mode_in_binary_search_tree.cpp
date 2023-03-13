#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

#include "leetcode.h"

using namespace std;


// 中序遍历就是有序数组，那么变成如何在有序数组中找到众数
vector<int> find_mode(TreeNode* root)
{
    vector<int> res;
    int maxcnt = 0, pre = root->val, cnt = 0;

    auto traverse = [&maxcnt, &res](auto&& self, TreeNode *cur, int& pre, int& cnt) -> void {
        if (cur == nullptr) return ;

        self(self, cur->left, pre, cnt);
        if (cur->val == pre) {
            ++cnt;
        } else {
            cnt = 1;
            pre = cur->val;
        }

        if (cnt == maxcnt) {
            res.push_back(cur->val);
        } else if (cnt > maxcnt) {
            maxcnt = cnt;
            res.clear();
            res.push_back(cur->val);
        }
        self(self, cur->right, pre, cnt);
    };

    traverse(traverse, root, pre, cnt);

    return res;
}

vector<int> __find_mode(TreeNode *root)
{
    vector<int> res;
    unordered_map<int, int> m;
    queue<TreeNode*> q;
    TreeNode *cur = nullptr;
    q.push(root);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        m[cur->val]++;
        if (cur->left != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
    }
    vector<pair<int,int>> v;
    for (const auto& e : m) v.emplace_back(e);
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int, int> b){
            return a.second > b.second;
            });

    int cnt = v.front().second;
    for (const auto& e : v) {
        if (e.second == cnt) res.push_back(e.first);
        else break;
    }

    return res;
}

void dfs(TreeNode *cur, int& pre, vector<int>& res, int& max_cnt, int& cnt)
{
    if (cur == nullptr) return ;
    dfs(cur->left, pre, res, max_cnt, cnt);
    if (cur->val == pre) {
        ++cnt;
    } else {
        cnt = 1;
        pre = cur->val;
    }
    if (cnt == max_cnt) {
        res.push_back(cur->val);
    }
    if (cnt > max_cnt) {
        max_cnt = cnt;
        res = vector<int> { cur->val };
    }
    dfs(cur->right, pre, res, max_cnt, cnt);
}

vector<int> _find_mode(TreeNode *root)
{
    vector<int> res;
    int pre = INT_MIN, max_cnt = 0, cnt = 0;
    dfs(root, pre, res, max_cnt, cnt);
    return res;
}

int main()
{
    vector<int> vec1 { 1, -1, 2, 2 };
    TreeNode *tree1 = build_tree(vec1);
    vector<int> res1 = find_mode(tree1);
    cout << res1 << endl;

    vector<int> vec2 { 2, 1 };
    TreeNode *tree2 = build_tree(vec2);
    vector<int> res2 = find_mode(tree2);
    cout << res2 << endl;
    return 0;
}
