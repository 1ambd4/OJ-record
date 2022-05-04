#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#include "leetcode.h"

using namespace std;

// int count_nodes(TreeNode *root)
// {
//     if (root == nullptr) return 0;
// 
//     int res = 0;
//     queue<TreeNode*> q;
//     TreeNode *cur = nullptr;
//     q.push(root);
// 
//     while (!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < q.size(); ++i) {
//             ++res;
//             cur = q.front();
//             q.pop();
//             if (cur->left != nullptr) q.push(cur->left);
//             if (cur->right != nullptr) q.push(cur->right);
//         }
//     }
// 
//     return res;
// }

void preorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    ++res;
    preorder(root->left, res);
    preorder(root->right, res);
}

void inorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    inorder(root->left, res);
    ++res;
    inorder(root->right, res);
}

void postorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    postorder(root->left, res);
    postorder(root->right, res);
    ++res;
}

// int count_nodes(TreeNode *root)
// {
//     if (root == nullptr) return 0;
//     int res = 0;
//     // preorder(root, res);
//     // inorder(root, res);
//     postorder(root, res);
//     return res;
// }
// 
// int count_nodes(TreeNode *root)
// {
//     if (root == nullptr) return 0;
//     return count_nodes(root->left) + count_nodes(root->right) + 1;
// }

int count_nodes(TreeNode *root)
{
    if (root == nullptr) return 0;

    int lh = 0, rh = 0;
    TreeNode *lt = root, *rt = root;
    while (lt != nullptr) {
        ++lh;
        lt = lt->left;
    }
    while (rt != nullptr) {
        ++rh;
        rt = rt->right;
    }
    if (lh == rh) {
        return pow(2, lh) - 1;
    }

    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int main()
{
    vector<int> vec1 { 1, 2, 3, 4, 5, 6 };
    TreeNode *tree1 = build_tree(vec1);
    cout << count_nodes(tree1) << endl;
    return 0;
}
