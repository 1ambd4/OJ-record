#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode *build(vector<int>& preorder, int plo, int phi,
                vector<int>& inorder, int ilo, int ihi)
{
    if (plo > phi) return nullptr;
    
    // 找到根在中序序列中的索引
    int rootval = preorder[plo], index = 0;
    for (int i = ilo; i <= ihi; ++i) {
        if (inorder[i] == rootval) {
            index = i;
            break;
        }
    } 

    TreeNode *root = new TreeNode(preorder[plo]);
    root->left = build(preorder, plo+1, plo+index-ilo,
            inorder, ilo, index-1);
    root->right = build(preorder, plo+index-ilo+1, phi,
            inorder, index+1, ihi);

    return root;
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder)
{
    return build(preorder, 0, preorder.size()-1,
            inorder, 0, inorder.size()-1);
}

int main()
{
    vector<int> pre1{3,9,20,15,7}, in1{9,3,15,20,7};
    TreeNode *res1 = build(pre1, in1);
    traversal(res1);

    vector<int> pre2{1}, in2{1};
    TreeNode *res2 = build(pre2, in2);
    traversal(res2);

    return 0;
}
