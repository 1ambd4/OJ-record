#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* build(vector<int>& inorder, int ilo, int ihi,
        vector<int>& postorder, int plo, int phi)
{
    if (ilo > ihi) return nullptr;

    int rootval = postorder[phi], index = 0;
    for (int i = ilo; i <= ihi; ++i) {
        if (inorder[i] == rootval) {
            index = i;
            break;
        }
    }

    TreeNode *root = new TreeNode(rootval);
    root->left = build(inorder, ilo, index-1,
            postorder, plo, plo+index-ilo-1);
    root->right = build(inorder, index+1, ihi,
            postorder, plo+index-ilo, phi-1);

    return root;
}

TreeNode* build(vector<int>& inorder, vector<int>& postorder)
{
    return build(inorder, 0, inorder.size()-1,
            postorder, 0, postorder.size()-1);
}

int main()
{
    vector<int> in1{9,3,15,20,7}, post1{9,15,7,20,3};
    TreeNode *res1 = build(in1, post1);
    traversal(res1);
    return 0;
}
