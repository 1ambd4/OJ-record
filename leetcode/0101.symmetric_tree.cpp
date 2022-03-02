#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

bool isSymmetric(TreeNode *left, TreeNode *right);
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr) {
        return true;
    }

    return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode *left, TreeNode *right)
{
    if (left == nullptr || right == nullptr) {
        return left == right;
    } else if (left->val != right->val) {
        return false;
    }

    return isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
}

int main()
{
    vector<int> case1 {1, 2, 2, 3, 4, 4, 3};
    TreeNode *tree1 = build_tree(case1);
    cout << isSymmetric(tree1) << endl;

    vector<int> case2 {1, 2, 2, -1, 3, -1, 3};
    TreeNode *tree2 = build_tree(case2);
    cout << isSymmetric(tree2) << endl;
    return 0;
}
