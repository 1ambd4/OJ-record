#include <algorithm>
#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void preorder(TreeNode *root, vector<int>& nums)
{
    if (root == nullptr) {
        return ;
    }

    nums.push_back(root->val);
    preorder(root->left, nums);
    preorder(root->right, nums);

    return ;
}

vector<int> preorder_traversal(TreeNode *root)
{
    if (root == nullptr) {
        return { };
    }

    vector<int> ans;
    preorder(root, ans);

    return ans;
}

int main()
{
    vector<int> case1 { 1, -1, 2 }; // 1, -1, 2, 3 };
    TreeNode *tree = build_tree(case1);
    vector<int> ans1 = preorder_traversal(tree);
    for_each(ans1.begin(), ans1.end(), [](int num){ cout << num << " "; });
    // preorder_traversal(tree);
    return 0;
}
