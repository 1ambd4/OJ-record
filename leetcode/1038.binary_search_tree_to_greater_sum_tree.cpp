#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* bst_to_gst(TreeNode *root)
{
    int sum = 0;

    auto traverse = [&sum](auto&& self, TreeNode *root) {
        if (root == nullptr) return ;

        self(self, root->right);
        sum += root->val;
        root->val = sum;
        self(self, root->left);
    };

    traverse(traverse, root);

    return root;
}

void inorder(TreeNode *root, int& sum)
{
    if (root == nullptr) return ;
    inorder(root->right, sum);
    sum += root->val;
    root->val = sum;
    inorder(root->left, sum);
}

TreeNode* _bst_to_gst(TreeNode *root)
{
    int sum = 0;
    inorder(root, sum);
    return root;
}

int main()
{
    vector<int> vec1{4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode *tree1 = build_tree(vec1);
    traversal(tree1);
    TreeNode *res1 = bst_to_gst(tree1);
    traversal(res1);

    vector<int> vec2{0,-1,1};
    TreeNode *tree2 = build_tree(vec2);
    traversal(tree2);
    TreeNode *res2 = bst_to_gst(tree2);
    traversal(res2);
    return 0;
}
