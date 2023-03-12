#include <algorithm>
#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> postorder_traversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    vector<int> left = postorder_traversal(root->left);
    vector<int> right = postorder_traversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(root->val);

    return res;
}

vector<int> _postorder_traversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    auto addall = [](vector<int>& res, vector<int> nums) {
        for (const auto& num : nums) res.push_back(num);
    };

    addall(res, postorder_traversal(root->left));
    addall(res, postorder_traversal(root->right));
    res.push_back(root->val);

    return res;
}

void traverse(TreeNode *cur, vector<int>& res)
{
    if (cur == nullptr) return ;

    traverse(cur->left, res);
    traverse(cur->right, res);
    res.push_back(cur->val);

    return ;
}

vector<int> __postorder_traversal(TreeNode *root)
{
    vector<int> res;
    traverse(root, res);
    return res;
}

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

int main()
{
    vector<int> case1 {1, -1, 2, 3 };
    TreeNode *tree = build_tree(case1);
    vector<int> ans1 = postorder_traversal(tree);
    for_each(ans1.begin(), ans1.end(), [](int num){ cout << num << " "; });
    // preorder_traversal(tree);

    return 0;
}
