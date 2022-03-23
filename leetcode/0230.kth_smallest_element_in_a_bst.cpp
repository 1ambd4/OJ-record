#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void inorder(TreeNode *root, int& k, int& r, int &s)
{
    if (root == nullptr) return;
    inorder(root->left, k, r, s);
    r++;
    if (r == k) {
        s = root->val;
    }
    inorder(root->right, k, r, s);
}

int kth_smallest(TreeNode *root, int k)
{
    int r = 0, s = 0;
    inorder(root, k, r, s);
    return s;
}

int main()
{
    vector<int> vec1 {3,1,4,-1,2};
    TreeNode *tree1 = build_tree(vec1);
    cout << kth_smallest(tree1, 1) << endl;

    vector<int> vec2 {5,3,6,2,4,-1,-1,1};
    TreeNode *tree2 = build_tree(vec2);
    cout << kth_smallest(tree2, 3) << endl;

    return 0;
}
