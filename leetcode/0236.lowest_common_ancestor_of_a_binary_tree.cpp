#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* lowest_common_ancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;

    TreeNode *left = lowest_common_ancestor(root->left, p, q);
    TreeNode *right = lowest_common_ancestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
        return root;
    }

    if (left == nullptr && right == nullptr) {
        return nullptr;
    }

    return left == nullptr ? right : left;
}

// 不知道为啥返回的是nullptr
// 知道哩，递归最后的返回值究竟是哪个很难判断啊
// 比如这里就返回了很多次
// 完全有可能最后拿到的返回值是nullptr
// 但base case就是得返回个啥东西才行
// 因而这么写递归是不合适的
// TreeNode* traverse(TreeNode *root, int val)
// {
//     if (root == nullptr) {
//         LOG("NOT HERE");
//         return nullptr;
//     }
//
//     if (root->val == val) {
//         cout << "found!!! " << root->val << endl;
//         return root;
//     }
//     traverse(root->left, val);
//     traverse(root->right, val);
// }


// 这个traverse还真不好写
// 递归要想拿到参数好麻烦啊
void traverse(TreeNode *root, int val, TreeNode **res)
{
    if (root == nullptr) return ;

    if (root->val == val) {
        *res = root;
        return ;
    }
    traverse(root->left, val, res);
    traverse(root->right, val, res);

    return ;
}

int main()
{
    vector<int> nums1 {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode *tree1 = build_tree(nums1);
    // TreeNode *p1 = traverse(tree1, 5);
    // TreeNode *q1 = traverse(tree1, 1);
    TreeNode *p1, *q1;
    traverse(tree1, 5, &p1);
    traverse(tree1, 1, &q1);
    TreeNode *res = lowest_common_ancestor(tree1, p1, q1);
    cout << res->val << endl;

    return 0;
}

