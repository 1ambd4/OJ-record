#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

int count(TreeNode *root, bool& flag)
{
    if (root == nullptr) return 0;

    int lh = count(root->left, flag);
    int rh = count(root->right, flag);

    if (abs(lh-rh) > 1) flag = false;

    return max(lh, rh) + 1;
}

bool is_balanced(TreeNode *root)
{
    bool flag = true;
    count(root, flag);
    return flag;
}

int main()
{
    vector<int> vec1 { 3, 9, 20, -1, -1, 15, 7 };
    TreeNode *tree1 = build_tree(vec1);
    cout << is_balanced(tree1) << endl;
    return 0;
}
