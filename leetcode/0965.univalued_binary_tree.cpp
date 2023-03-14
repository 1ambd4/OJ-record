#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

bool is_unival_tree(TreeNode *root)
{
    if (root == nullptr) return true;

    int pre = root->val;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *cur = nullptr;

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();

            if (cur->val != pre) return false;

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
    }

    return true;
}

bool _is_unival_tree(TreeNode *root)
{
    bool res = true;
    if (root == nullptr) return res;

    int pre = root->val;
    auto traverse = [&res, &pre](auto&& self, TreeNode *root) -> void {
        if (root == nullptr) return ;

        if (root->val != pre) res = false;
        self(self, root->left);
        self(self, root->right);
    };

    traverse(traverse, root);

    return res;
}

int main()
{
    vector<int> nums1 {1,1,1,1,1,-1,1};
    TreeNode *tree1 = build_tree(nums1);
    cout << is_unival_tree(tree1) << endl;

    vector<int> nums2 {2,2,2,5,2};
    TreeNode *tree2 = build_tree(nums2);
    cout << is_unival_tree(tree2) << endl;

    return 0;
}

