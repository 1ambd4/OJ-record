#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

TreeNode* lowest_common_ancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *ancestor = root;
    for ( ; ; ) {
        if (p->val < ancestor->val && q->val < ancestor->val) {
            ancestor = ancestor->left;
        } else if (p->val > ancestor->val && q->val > ancestor->val) {
            ancestor = ancestor->right;
        } else {
            break;
        }
    }

    return ancestor;
}

int main()
{
    vector<int> vec1 { 6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5 };
    return 0;
}
