#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

TreeNode* merge_trees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr || root2 == nullptr) {
        return root1 == nullptr ? root2 : root1;
    }

    TreeNode *merged = new TreeNode(root1->val + root2->val);
    merged->left = merge_trees(root1->left, root2->left);
    merged->right = merge_trees(root1->right, root2->right);

    return merged;
}

TreeNode* _merge_trees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr || root2 == nullptr) {
        return root1 == nullptr ? root2 : root1;
    }

    queue<TreeNode*> q, q1, q2;
    TreeNode *merged = new TreeNode(root1->val + root2->val);
    TreeNode *node = nullptr, *node1 = nullptr, *node2 = nullptr;
    q.push(merged), q1.push(root1), q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        node = q.front(); q.pop();
        node1 = q1.front(); q1.pop();
        node2 = q2.front(); q2.pop();
        if (node1->left != nullptr || node2->left != nullptr) {
            if (node1->left != nullptr && node2->left != nullptr) {
                node->left = new TreeNode(node1->left->val + node2->left->val);
                q.push(node->left);
                q1.push(node1->left);
                q2.push(node2->left);
            } else {
                node->left = (node1->left == nullptr ? node2->left : node1->left);
            }
        }
        if (node1->right != nullptr || node2->right != nullptr) {
            if (node1->right != nullptr && node2->right != nullptr) {
                node->right = new TreeNode(node1->right->val + node2->right->val);
                q.push(node->right);
                q1.push(node1->right);
                q2.push(node2->right);
            } else {
                node->right = (node1->right == nullptr ? node2->right : node1->right);
            }
        }
    }

    return merged;
}

int main()
{
    vector<int> vec1 = { 1, 3, 2, 5 }, vec2 { 2, 1, 3, -1, 4, -1, 7 };
    TreeNode *tree1 = build_tree(vec1), *tree2 = build_tree(vec2);
    TreeNode *res1 = _merge_trees(tree1, tree2);
    traversal(res1);
    return 0;
}
