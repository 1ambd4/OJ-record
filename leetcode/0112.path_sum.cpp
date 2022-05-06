#include <iostream>
#include "leetcode.h"

using namespace std;

void traverse(TreeNode *root, bool &found, int sum)
{
    if (root == nullptr) return ;

    sum -= root->val;
    if (root->left == root->right && sum == 0) {
        found = true;
        return ;
    }
    traverse(root->left, found, sum);
    traverse(root->right, found, sum);
    sum += root->val;
}

bool has_path_sum(TreeNode *root, int target_sum)
{
    int res = 0;
    bool found = false;
    traverse(root, found, target_sum);
    return found;
}

bool _has_path_sum(TreeNode *root, int targetSum) {
    // base case
    // 1、搜到树外面去了
    // 2、搜到叶结点，且正好构成路径（左子树和右子树只有在都为空的情况下才可能相等，学到了）
    if (root == nullptr) {
        return false;
    }
    if (root->left == root->right && root->val == targetSum) {
        return true;
    }

    return has_path_sum(root->left, targetSum - root->val)
            || has_path_sum(root->right, targetSum - root->val);
}

int main()
{
    vector<int> case1 {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    TreeNode *root = build_tree(case1);
    cout << has_path_sum(root, 22) << endl;
    return 0;
}
