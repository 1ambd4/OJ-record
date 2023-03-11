#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void traversal(vector<int>& res, TreeNode* root)
{
    if (root == nullptr) return ;

    traversal(res, root->left);
    res.push_back(root->val);
    traversal(res, root->right);
}

vector<int> inorder_traversal(TreeNode* root)
{
    vector<int> res;
    traversal(res, root);
    return res;
}

int main()
{
    vector<int> nodes1 {1,-1,2,3};
    TreeNode *tree1 = build_tree(nodes1);
    vector<int> res1 = inorder_traversal(tree1);
    print_vector(res1);
    return 0;
}

