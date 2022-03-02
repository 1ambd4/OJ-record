#include <iostream>
#include "leetcode.h"

using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr) {
        return true;
    } else if (p == nullptr || q == nullptr) {
        return false;
    } else if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    vector<int> case1p { 1, 2, 3 };
    vector<int> case1q { 1, 2, 3 };
    TreeNode *tree1p = build_tree(case1p);
    TreeNode *tree1q = build_tree(case1q);
    cout << isSameTree(tree1p, tree1q) << endl;

    return 0;
}
