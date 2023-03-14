#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

#include "leetcode.h"

using namespace std;

vector<TreeNode*> find_duplicate_subtree(TreeNode *root)
{
    vector<TreeNode*> res;
    if (root == nullptr) return res;

    unordered_map<string, int> m;
    auto traverse = [&res, &m](auto&& self, TreeNode *root) -> string {
        if (root == nullptr) return "#";

        string left = self(self, root->left);
        string right = self(self, root->right);
        string tree = left + "," + right + "," + to_string(root->val);

        if (++m[tree] == 2) {
            res.push_back(root);
        }

        return tree;
    };

    traverse(traverse, root);

    return res;
}

// TLE了，我不理解，不卡dfs，卡bfs？
// string serialize(TreeNode *root)
// {
//     if (root == nullptr) return "#";
//
//     string left = serialize(root->left);
//     string right = serialize(root->right);
//
//     return left + "," + right + "," + to_string(root->val);
// }
//
// // 任意方式遍历二叉树的同时进行序列化后添加进map
// // 因而若有序列化后结果相同的，判定为重复子树
// vector<TreeNode*> find_duplicate_subtree(TreeNode *root)
// {
//     vector<TreeNode*> res;
//     if (root == nullptr) return res;
//
//     unordered_map<string, int> m;
//     TreeNode *cur = nullptr;
//     queue<TreeNode*> q;
//     q.push(root);
//     while (!q.empty()) {
//         cur = q.front();
//         q.pop();
//         string s = serialize(cur);
//         m[s]++;
//         if (m[s] == 2) {
//             res.push_back(cur);
//         }
//         if (cur->left != nullptr) {
//             q.push(cur->left);
//         }
//         if (cur->right != nullptr) {
//             q.push(cur->right);
//         }
//     }
//
//     return res;
// }

string serialize(TreeNode *root, vector<TreeNode*>& res,
        unordered_map<string, int>& m)
{
    if (root == nullptr) return "#";

    string left = serialize(root->left, res, m);
    string right = serialize(root->right, res, m);
    string tree = left + "," + right + "," + to_string(root->val);

    m[tree]++;
    if (m[tree] == 2) {
        res.push_back(root);
    }

    return tree;
}

vector<TreeNode*> _find_duplicate_subtree(TreeNode *root)
{
    vector<TreeNode*> res;
    if (root == nullptr) return res;
    unordered_map<string, int> m;
    serialize(root, res, m);
    return res;
}

int main()
{
    vector<int> vec1 {1,2,3,4,-1,2,4,-1,-1,4};
    TreeNode *tree1 = build_tree(vec1);
    vector<TreeNode*> res1 = find_duplicate_subtree(tree1);
    for (const auto& e : res1) {
        cout << e->val << " ";
    }
    cout << endl;
    return 0;
}
