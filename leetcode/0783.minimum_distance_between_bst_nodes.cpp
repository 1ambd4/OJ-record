#include <iostream>
#include <vector>
#include <limits>

#include "leetcode.h"

using namespace std;

int min_diff_in_bst(TreeNode *root)
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

int main()
{
    vector<int> nums1 = {4,2,6,1,3};
    TreeNode *tree1 = build_bst(nums1);
    cout << min_diff_in_bst(tree1) << endl;

    return 0;
}

