#include <iostream>
#include <vector>
#include <climits>

#include "leetcode.h"

using namespace std;

TreeNode* build(vector<int>& nums, int lo, int hi)
{
    if (lo > hi) return nullptr;

    int maxval = nums[lo], index = lo;
    for (int i = lo; i <= hi; ++i) {
        if (nums[i] > maxval) {
            maxval = nums[i];
            index = i;
        }
    }
    
    TreeNode *root = new TreeNode(maxval);
    root->left = build(nums, lo, index-1);
    root->right = build(nums, index+1, hi);

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
