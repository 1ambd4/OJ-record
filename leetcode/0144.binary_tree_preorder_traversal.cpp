#include <algorithm>
#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> preorder_traversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    res.push_back(root->val);
    vector<int> left = preorder_traversal(root->left);
    vector<int> right = preorder_traversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());

    return res;
}

vector<int> __preorder_traversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    auto addall = [](vector<int>& res, vector<int> nums) {
        for (const auto& num : nums) {
            res.push_back(num);
        }
    };

    res.push_back(root->val);
    addall(res, preorder_traversal(root->left));
    addall(res, preorder_traversal(root->right));

    return res;
}

void traverse(TreeNode *cur, vector<int>& res)
{
    if (cur == nullptr) return ;

    res.push_back(cur->val);
    traverse(cur->left, res);
    traverse(cur->right, res);

    return ;
}

vector<int> _preorder_traversal(TreeNode *root)
{
    vector<int> res;
    traverse(root, res);
    return res;
}


void _preorder(TreeNode *root, vector<int>& nums)
{
    if (root == nullptr) {
        return ;
    }

    nums.push_back(root->val);
    _preorder(root->left, nums);
    _preorder(root->right, nums);

    return ;
}

vector<int> ___preorder_traversal(TreeNode *root)
{
    if (root == nullptr) {
        return { };
    }

    vector<int> ans;
    _preorder(root, ans);

    return ans;
}

int main()
{
    vector<int> case1 {1, -1, 2, 3 };
    TreeNode *tree = build_tree(case1);
    vector<int> ans1 = preorder_traversal(tree);
    for_each(ans1.begin(), ans1.end(), [](int num){ cout << num << " "; });
    // preorder_traversal(tree);

    return 0;
}
