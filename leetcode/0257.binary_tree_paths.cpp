#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void traversal(TreeNode *root, vector<string>& res, vector<int>& path)
{
    if (root == nullptr) return ;

    if (root->left == nullptr && root->right == nullptr) {
        path.push_back(root->val);
        res.push_back("");
        for (int i = 0; i < path.size(); ++i) {
            res.back() += to_string(path[i]);
            if (i != path.size() - 1) {
                res.back() += "->";
            }
        }
        path.pop_back();
        return ;
    }

    path.push_back(root->val);
    traversal(root->left, res, path);
    traversal(root->right, res, path);
    path.pop_back();
}

vector<string> binary_tree_paths(TreeNode *root)
{
    vector<string> res;
    vector<int> path;
    traversal(root, res, path);
    return res;
}

int main()
{
    vector<int> vec1 { 1, 2, 3, -1, 5 };
    TreeNode *tree1 = build_tree(vec1);
    vector<string> res1 = binary_tree_paths(tree1);
    cout << res1 << endl;
    return 0;
}
