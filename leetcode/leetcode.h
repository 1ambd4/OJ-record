#ifndef LEETCODE_H_
#define LEETCODE_H_

#include <queue>
#include <vector>

struct ListNode {
    public:
        ListNode() : val(0), next(nullptr) { }
        ListNode(int x) : val(x), next(nullptr) { };
        ListNode(int x, ListNode *next) : val(x), next(next) { };

        int val;
        ListNode *next;
};

ListNode* build_list(std::vector<int> nums)
{
    ListNode *head = new ListNode();
    ListNode *cur = head;
    for (const int& num : nums) {
        ListNode *temp = new ListNode(num);
        cur->next = temp;
        cur = cur->next;
    }
    return head->next;
}

void show_list(ListNode *head)
{
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout  << std::endl;
}

std::ostream& operator << (std::ostream& os, ListNode *head)
{
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    return os;
}

struct TreeNode {
    public:
        TreeNode() : val(0), left(nullptr), right(nullptr) { }
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }

        int val;
        TreeNode *left, *right;
};

// 1, null, 2, 3 层次遍历建树
TreeNode* build_tree(std::vector<int>& nums)
{
    if (nums.size() == 0) return nullptr;
    TreeNode *head = new TreeNode(nums[0]), *cur = head, *temp;
    std::queue<TreeNode*> q;
    q.push(cur);
    for (int i = 1; i < nums.size(); i+=2) {
        cur = q.front();
        q.pop();
        if (i < nums.size()) {
            if (nums[i] != -1) {
                temp = new TreeNode(nums[i]);
                cur->left = temp;
                q.push(temp);
            } else {
                cur->left = nullptr;
            }
        }
        if (i+1 < nums.size()) {
            if (nums[i+1] != -1) {
                temp = new TreeNode(nums[i+1]);
                cur->right = temp;
                q.push(temp);
            } else {
                cur->right = nullptr;
            }
        }
    }
    return head;
}

// 层序遍历
void traversal(TreeNode *head)
{
    if (head == nullptr) return ;
    TreeNode *cur;
    std::queue<TreeNode*> q;
    q.push(head);
    std::cout << head->val << " ";
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->left != nullptr) {
            q.push(cur->left);
            std::cout << cur->left->val << " ";
        } else {
            std::cout << "null ";
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
            std::cout << cur->right->val << " ";
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
void print_vector(std::vector<T> vec)
{
    for (const auto &it : vec) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::ostream& operator << (std::ostream& os, std::vector<T> v)
{
    for (const auto& e : v) {
        os << e << ' ';
    }
    return os;
}

template <typename T>
std::ostream& operator << (std::ostream& os, std::vector<std::vector<T>> vs)
{
    for (const auto& v : vs) {
        os << '[';
        for (const auto& e : v) {
            os << e << ',';
        }
        os << ']';
    }
    return os;
}

#endif  // LEETCODE_H
