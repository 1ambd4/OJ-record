#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> postorder(Node *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    auto traverse = [&res](auto&& self, Node *root) -> void {
        if (root == nullptr) return ;

        for (const auto& child : root->children) {
            self(self, child);
        }
        res.push_back(root->val);
    };

    traverse(traverse, root);

    return res;
}

int main()
{
    vector<int> nums1 {1,-1,3,2,4,-1,5,6};
    Node *tree1 = build_nbt(nums1);
    vector<int> res1 = postorder(tree1);
    cout << res1 << endl;

    return 0;
}

