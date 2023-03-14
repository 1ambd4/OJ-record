#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> preorder(Node *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    auto traverse = [&res](auto&& self, Node *root) -> void {
        if (root == nullptr) return ;

        res.push_back(root->val);
        for (const auto& child : root->children) {
            self(self, child);
        }
    };

    traverse(traverse, root);

    return res;
}

// 太不优雅啦
// vector<int> res;
//
// void preorder_(Node* root)
// {
//     if (root == nullptr) return ;
//
//     res.push_back(root->val);
//     for (const auto& child : root->children) {
//         preorder_(child);
//     }
// }
//
// vector<int> preorder(Node* root)
// {
//     preorder_(root);
//     return res;
// }

int main()
{
    vector<int> nums1 {1,-1,3,2,4,-1,5,6};
    Node *tree1 = build_nbt(nums1);
    vector<int> res1 = preorder(tree1);
    cout << res1 << endl;

    return 0;
}

