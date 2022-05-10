#include <iostream>
#include <vector>
#include <climits>

#include "leetcode.h"

using namespace std;

TreeNode* build(vector<int>& nums, int left, int right)
{
    if (left > right) return nullptr;

    int maxval = nums[left], index = left;
    for (int i = left; i <= right; ++i) {
        if (nums[i] > maxval) {
            maxval = nums[i];
            index = i;
        }
    }
    
    TreeNode *root = new TreeNode(maxval);
    root->left = build(nums, left, index-1);
    root->right = build(nums, index+1, right);

    return root;
}

TreeNode* construct_maximum_binary_tree(vector<int>& nums)
{
    return build(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> vec1{3,2,1,6,0,5};
    TreeNode *res1 = construct_maximum_binary_tree(vec1);
    traversal(res1);

    vector<int> vec2{3,2,1};
    TreeNode *res2 = construct_maximum_binary_tree(vec2);
    traversal(res2);

    return 0;
}
