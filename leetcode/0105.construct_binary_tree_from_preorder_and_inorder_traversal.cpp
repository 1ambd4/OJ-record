#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// build
// 二叉树递归的问题，要往左右子树上想
// 这里的话，就是拿到rootval构建根节点之后递归的构造左右子树
// 那么，构造左右子树的过程实际上和构造根节点的过程是一样的
// 便将此定义为递归函数
TreeNode* build(vector<int>& preorder, int plo, int phi,
        vector<int>& inorder, int ilo, int ihi)
{
    if (plo > phi) return nullptr;

    // 在inorder里找到rootval，则rootval将序列分成左右两边
    int rootval = preorder[plo], index = 0;
    for (int i = ilo; i <= ihi; ++i) {
        if (inorder[i] == rootval) {
            index = i;
            break;
        }
    }

    int leftsize = index - ilo;

    TreeNode *root = new TreeNode(rootval);
    root->left = build(preorder, plo+1, plo+leftsize,
                    inorder, ilo, index-1);
    root->right = build(preorder, plo+leftsize+1, phi,
                    inorder, index+1, ihi);
    return root;
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder)
{
    return build(preorder, 0, preorder.size()-1,
            inorder, 0, inorder.size()-1);
}



TreeNode* _build(vector<int>& preorder, int plo, int phi,
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

TreeNode* _build(vector<int>& preorder, vector<int>& inorder)
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
