#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> res;

void preorder_(Node* root)
{
    if (root == nullptr) return ;

    res.push_back(root->val);
    for (const auto& child : root->children) {
        preorder_(child);
    }
}

vector<int> preorder(Node* root)
{
    preorder_(root);
    return res;
}

int main()
{
    return 0;
}

