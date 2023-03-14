#include <iostream>
#include <vector>
#include <limits>

#include "leetcode.h"

using namespace std;

bool is_valid_bst(TreeNode *root)
{
    auto traverse = [](auto&& self, TreeNode *root, TreeNode *min, TreeNode *max) -> bool {
        if (root == nullptr) return true;

        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;

        return self(self, root->left, min, root) && self(self, root->right, root, max);
    };

    return traverse(traverse, root, nullptr, nullptr);
}

bool _is_valid_bst(TreeNode *root)
{
    bool res = true;
    if (root == nullptr) return res;

    auto traverse = [](auto&& self, TreeNode *root, bool& res, long& pre) -> void {
        if (root == nullptr) return ;

        self(self, root->left, res, pre);
        if (root->val <= pre) res = false;
        pre = root->val;
        self(self, root->right, res, pre);
    };

    long pre = numeric_limits<long>::min();
    traverse(traverse, root, res, pre);

    return res;
}

int main()
{
    vector<int> nums1 {2,1,3};
    TreeNode *tree1 = build_tree(nums1);
    cout << is_valid_bst(tree1) << endl;

    vector<int> nums2 {5,1,4,-1,-1,3,6};
    TreeNode *tree2 = build_tree(nums2);
    cout << is_valid_bst(tree2) << endl;

    vector<int> nums3 {2,2,2};
    TreeNode *tree3 = build_tree(nums3);
    cout << is_valid_bst(tree3) << endl;

    vector<int> nums4 {-2147483648};
    TreeNode *tree4 = build_tree(nums4);
    cout << is_valid_bst(tree4) << endl;

    return 0;
}

