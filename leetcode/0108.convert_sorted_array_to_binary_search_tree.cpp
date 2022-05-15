#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

TreeNode* build(vector<int>& nums, int left, int right)
{
    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid-1);
    root->right = build(nums, mid+1, right);

    return root;
}

// [left,right]建树
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return build(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> case1 {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(case1);
    traversal(root);
    return 0;
}
