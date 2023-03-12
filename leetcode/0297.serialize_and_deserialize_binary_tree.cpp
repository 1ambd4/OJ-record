#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <strstream>

#include "leetcode.h"

using namespace std;

// TODO 层次遍历的方式有点儿问题（也可能是很大的问题
// 层次遍历序列化和反序列化
// string serialize(TreeNode *root)
// {
//     strstream ss;
//     if (root == nullptr) return "";
//     queue<TreeNode*> q;
//     q.push(root);
//     TreeNode *cur = nullptr;
//
//     ss << root->val;
//     while (!q.empty()) {
//         int n = q.size();
//         for (int i = 0; i < n; ++i) {
//             cur = q.front();
//             q.pop();
//
//             if (cur == nullptr) {
//                 ss << "," << "19260817";
//             } else {
//                 q.push(cur->left);
//                 q.push(cur->right);
//                 ss << "," << cur->val;
//             }
//         }
//     }
//
//     return ss.str();
// }
//
// TreeNode* deserialize(string data)
// {
//     // 判断一下空字符串
//     LOG(data);
//     if (data.size() == 0) return nullptr;
//
//     stringstream ss(data);
//     queue<TreeNode*> q;
//     TreeNode *cur = nullptr, *tmp = nullptr;
//
//     int num;
//     char ch;
//
//     ss >> num;
//     if (num == 19260817) return nullptr;
//
//     TreeNode *root = new TreeNode(num);
//     q.push(root);
//
//     while (!q.empty()) {
//         int  n = q.size();
//         for (int i = 0; i < n; ++i) {
//             cur = q.front();
//             q.pop();
//
//             if (cur != nullptr) {
//                 ss >> ch >> num;
//                 if (num != 19260817) {
//                     tmp = new TreeNode(num);
//                     q.push(tmp);
//                     cur->left = tmp;
//                 } else {
//                     cur->left = nullptr;
//                 }
//
//                 ss >> ch >> num;
//                 if (num != 19260817) {
//                     tmp = new TreeNode(num);
//                     q.push(tmp);
//                     cur->right = tmp;
//                 } else {
//                     cur->right = nullptr;
//                 }
//             }
//         }
//     }
//
//     return root;
// }

// 序列化拼接字符串时，用的是根左右的先序序列
// 那么反序列化的时候，也应该用先序
string serialize(TreeNode *root)
{
    if (root == nullptr) return "19260817";
    string left = serialize(root->left);
    string right = serialize(root->right);

    return to_string(root->val) + "," + left + "," + right;
}

TreeNode* deserialize(queue<int>& nums)
{
    if (nums.empty()) return nullptr;

    int num = nums.front();
    nums.pop();
    if (num == 19260817) return nullptr;

    TreeNode *root = new TreeNode(num);
    root->left = deserialize(nums);
    root->right = deserialize(nums);

    return root;
}

TreeNode* deserialize(string data)
{
    int num;
    char ch;
    stringstream ss(data);
    ss >> num;
    if (num == 19260817) return nullptr;

    queue<int> nums;
    nums.push(num);
    while (ss >> ch >> num) {
        nums.push(num);
    }
    return deserialize(nums);
}


string __serialize(TreeNode *root)
{
    if (root == nullptr) return "19260817"; // 为了方便反序列化，空指针用特殊数值表示
    string left = __serialize(root->left);
    string right = __serialize(root->right);

    return to_string(root->val) + "," + left + "," + right;
}

TreeNode* __deserialize(queue<int>& nums)
{
    if (nums.empty()) return nullptr;

    int cur = nums.front();
    nums.pop();
    if (cur == 19260817) return nullptr;

    TreeNode *root = new TreeNode(cur);
    root->left = __deserialize(nums);
    root->right = __deserialize(nums);

    return root;
}

// 1,2,19260817,19260817,3,4,19260817,19260817,5,19260817,19260817
TreeNode* __deserialize(string data)
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
    return __deserialize(nums);
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

    vector<int> vec3 {1};
    TreeNode *root3 = build_tree(vec3);
    string data3 = serialize(root3);
    TreeNode *tree3 = deserialize(data3);
    traversal(tree3);

    vector<int> vec4 {1,2};
    TreeNode *root4 = build_tree(vec4);
    string data4 = serialize(root4);
    TreeNode *tree4 = deserialize(data4);
    traversal(tree4);

    return 0;
}
