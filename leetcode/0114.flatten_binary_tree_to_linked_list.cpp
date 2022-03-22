#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void flatten(TreeNode *root)
{
    if (root == nullptr) return ;

    // 拉平左右子树
    flatten(root->left);
    flatten(root->right);

    // 将右子树接到左子树上
    TreeNode *left = root->left, *right = root->right;  // 保存左右子树
    root->left = nullptr, root->right = left;   // 拉平之后左子树接到了右边
    // 这个时候左子树已经被拉平，并且接到了正确的位置
    // 那么将原右子树接过来，也就是让原右子树成为原左子树的右孩子即可
    TreeNode *cur = root;
    while (cur->right != nullptr) {
        cur = cur->right;
    }
    cur->right = right;
}

int main()
{
    vector<int> vec1{1,2,5,3,4,-1,6};
    TreeNode *tree1 = build_tree(vec1);
    flatten(tree1);
    traversal(tree1);

    vector<int> vec2{};
    TreeNode *tree2 = build_tree(vec2);
    flatten(tree2);
    traversal(tree2);
    return 0;
}
