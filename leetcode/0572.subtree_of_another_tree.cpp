#include <iostream>

#include "leetcode.h"

// 依次比较是否和当前相等，或者和子树相等
bool is_subtree(TreeNode *root, TreeNode *sub)
{
    auto is_sametree = [](auto&& self, TreeNode *t1, TreeNode *t2) -> bool {
        if (t1 == t2) return true;
        else if (t1 == nullptr || t2 == nullptr) return false;
        return t1->val == t2->val && self(self, t1->left, t2->left) && self(self, t1->right, t2->right);
    };

    if (root == sub) return true;
    else if (root == nullptr || sub == nullptr) return false;
    return is_sametree(is_sametree, root, sub) || is_subtree(root->left, sub) || is_subtree(root->right, sub);
}

int main()
{
    std::vector<int> r1 {3,4,5,1,2}, s1{4,1,2};
    TreeNode *tr1 = build_tree(r1), *ts1 = build_tree(s1);
    std::cout << is_subtree(tr1, ts1) << std::endl;
    return 0;
}
