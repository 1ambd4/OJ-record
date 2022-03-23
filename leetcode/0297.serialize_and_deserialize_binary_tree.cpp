#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "leetcode.h"

using namespace std;

string serialize(TreeNode *root)
{
    if (root == nullptr) return "19260817"; // 为了方便反序列化，空指针用特殊数值表示
    string left = serialize(root->left);
    string right = serialize(root->right);

    return to_string(root->val) + "," + left + "," + right;
}

TreeNode *deserialize(queue<int>& nums)
{
    if (nums.empty()) return nullptr;

    int cur = nums.front();
    nums.pop();
    if (cur == 19260817) return nullptr;

    TreeNode *root = new TreeNode(cur);
    root->left = deserialize(nums);
    root->right = deserialize(nums);

    return root;
}

// 1,2,19260817,19260817,3,4,19260817,19260817,5,19260817,19260817
TreeNode* deserialize(string data)
{
    int tmp;
    char ch;
    stringstream ss(data);
    ss >> tmp;
    if (tmp == 19260817) return nullptr;

    queue<int> nums;
    nums.push(tmp);
    while (ss >> ch >> tmp) {
        nums.push(tmp);
    }
    return deserialize(nums);
}

int main()
{
    vector<int> vec1 {1,2,3,-1,-1,4,5};
    TreeNode *root1 = build_tree(vec1);
    string data1 = serialize(root1);
    TreeNode *tree1 = deserialize(data1);
    traversal(tree1);

    vector<int> vec2 {};
    TreeNode *root2 = build_tree(vec2);
    string data2 = serialize(root2);
    TreeNode *tree2 = deserialize(data2);
    traversal(tree2);

    return 0;
}
