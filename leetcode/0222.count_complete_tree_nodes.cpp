#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#include "leetcode.h"

using namespace std;

int count_nodes(TreeNode *root)
{
    TreeNode *tl = root, *tr = root;
    int hl = 0, hr = 0;

    // 计算左右子树的高度
    // 需要注意的是，这里计算的高度并不是通常意义上说的子树高
    // 而是子树的最小高度
    // 因为是完全二叉树，故而如果不满一定最先出现在右子树
    // 故而这里左子树高度计算的是最左节点的高度
    // 右子树高度计算的是最右节点的高度
    while (tl != nullptr) {
        tl = tl->left;
        ++hl;
    }
    while (tr != nullptr) {
        tr = tr->right;
        ++hr;
    }

    // 当左右子树高度相同的时候，为满二叉树，直接用公式计算
    if (hl == hr) {
        return pow(2, hl) - 1;
    }

    // 否则各自计算左右子树的节点个数做累加
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int _count_nodes(TreeNode *root)
{
    if (root == nullptr) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}


void preorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    ++res;
    preorder(root->left, res);
    preorder(root->right, res);

    return ;
}

void inorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    inorder(root->left, res);
    ++res;
    inorder(root->right, res);

    return ;
}

void postorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    postorder(root->left, res);
    postorder(root->right, res);
    ++res;

    return ;
}

int __count_nodes(TreeNode *root)
{
    int res = 0;
    preorder(root, res);
    // inorder(root, res);
    // postorder(root, res);
    return res;
}

int ___count_nodes(TreeNode *root)
{
    int res = 0;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);
    TreeNode *cur = nullptr;

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        res += n;
    }

    return res;
}


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

void _preorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    ++res;
    preorder(root->left, res);
    preorder(root->right, res);
}

void _inorder(TreeNode *root, int& res)
{
    if (root == nullptr) return ;

    inorder(root->left, res);
    ++res;
    inorder(root->right, res);
}

void _postorder(TreeNode *root, int& res)
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

int ____count_nodes(TreeNode *root)
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
