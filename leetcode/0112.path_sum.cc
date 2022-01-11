#include <iostream>
#include "leetcode.h"

using namespace std;

void backtrace(TreeNode *root, int targetSum, int &res, bool &found)
{
    if (root == nullptr) {
        return ;
    }

    res += root->val;
    if (root->left == nullptr && root->right == nullptr) {
        if (res == targetSum) {
            found = true;
        }
    }
    backtrace(root->left, targetSum, res, found);
    backtrace(root->right, targetSum, res, found);
    res -= root->val;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    int res = 0;
    bool found = false;
    backtrace(root, targetSum, res, found);
    return found;
}

bool has_path_sum(TreeNode *root, int targetSum) {
    // base case
    // 1、搜到树外面去了
    // 2、搜到叶结点，且正好构成路径（左子树和右子树只有在都为空的情况下才可能相等，学到了）
    if (root == nullptr) {
        return false;
    }
    if (root->left == root->right && root->val = targetSum) {
        return true;
    }

    return has_path_sum(root->left, targetSum - root->val)
            || has_path_sum(root->right, targetSum - root->val);
}

int main()
{
    vector<int> case1 {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    TreeNode *root = build_tree(case1);
    cout << hasPathSum(root, 22) << endl;
    return 0;
}
