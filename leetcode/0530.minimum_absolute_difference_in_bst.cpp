#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#include "leetcode.h"

using namespace std;

int get_minimum_difference(TreeNode *root)
{
    int res = numeric_limits<int>::max(), pre = -1;

    auto traverse = [&res, &pre](auto&& self, TreeNode *root) -> void {
        if (root == nullptr) return ;

        self(self, root->left);
        if (pre != -1) res = min(res, root->val - pre);
        pre = root->val;
        self(self, root->right);
    };

    traverse(traverse, root);

    return res;
}

void traverse(TreeNode *root, int& ans, int& pre)
{
    if (root == nullptr) return ;

    traverse(root->left, ans, pre);
    if (pre != -1) ans = min(ans, root->val - pre);
    pre = root->val;
    traverse(root->right, ans, pre);
}

int _get_minimum_difference(TreeNode *root)
{
    int ans = INT_MAX, pre = -1;
    traverse(root, ans, pre);
    return ans;
}

int main()
{
    vector<int> vec1 { 4, 2, 6, 1, 3 };
    TreeNode* tree1 = build_tree(vec1);
    cout << get_minimum_difference(tree1) << endl;
    return 0;
}
