#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// 所谓二叉树的直径，其实就是左右子树的最大深度之和
int diameter_of_binary_tree(TreeNode *root)
{
    int res = 0;

    auto traverse = [&res](auto&& self, TreeNode *root) -> int {
        if (root == nullptr) return 0;

        int left  = self(self, root->left);
        int right = self(self, root->right);

        res = max(res, left + right);

        return 1 + max(left, right);
    };

    traverse(traverse, root);

    return res;
}

int main()
{
    vector<int> nums1 {1,2,3,4,5,-1,-1};
    TreeNode *tree1 = build_tree(nums1);
    cout << diameter_of_binary_tree(tree1) << endl;

    return 0;
}

