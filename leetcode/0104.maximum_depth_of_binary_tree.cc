#include <iostream>
#include "leetcode.h"

using namespace std;

int maxDepth(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 回溯
void traverse(TreeNode *root, int &depth, int &res);
int max_depth(TreeNode *root)
{
    int depth = 0, res = 0;
    traverse(root, depth, res);
    return res;
}
void traverse(TreeNode *root, int &depth, int &res)
{
    if (root == nullptr) {
        return ;
    }

    ++depth;
    res = max(res, depth);
    traverse(root->left, depth, res);
    traverse(root->right, depth, res);
    --depth;
}

int main()
{
    vector<int> case1 {3, 9, 20, -1, -1, 15, 7};
    TreeNode *tree1 = build_tree(case1);
    cout << maxDepth(tree1) << endl;
    cout << max_depth(tree1) << endl;
    return 0;
}
