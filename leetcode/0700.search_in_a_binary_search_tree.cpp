#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* search_bst(TreeNode *root, int val)
{
    if (root == nullptr) return nullptr;

    if (root->val < val) {
        return search_bst(root->right, val);
    } else if (root->val > val) {
        return search_bst(root->left, val);
    }

    return root;
}

int main()
{
    vector<int> vec1{4,2,7,1,3};
    TreeNode *tree1 = build_tree(vec1);
    TreeNode *res1 = search_bst(tree1, 2);
    traversal(res1);

    vector<int> vec2{4,2,7,3,1};
    TreeNode *tree2 = build_tree(vec2);
    TreeNode *res2 = search_bst(tree2, 5);
    traversal(res2);
    return 0;
}
