#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

bool is_sub(ListNode *head, TreeNode *root)
{
    if (head == nullptr) return true;
    if (root == nullptr) return false;
    if (head->val != root->val) return false;

    return is_sub(head->next, root->left) || is_sub(head->next, root->right);
}

bool is_sub_path(ListNode *head, TreeNode *root)
{
    if (head == nullptr) return true;
    if (root == nullptr) return false;

    return is_sub(head, root) || is_sub_path(head, root->left) || is_sub_path(head, root->right);
}

int main()
{
    vector<int> nums1 { 1, 4, 4, -1, 2, 2, -1, 1, -1, 6, 8, -1, -1, -1, -1, 1, 3 };
    vector<int> nums2 { 4, 2, 8 };
    TreeNode *tree1 = build_tree(nums1);
    ListNode *list1 = build_list(nums2);
    cout << is_sub_path(list1, tree1) << endl;

    return 0;
}

