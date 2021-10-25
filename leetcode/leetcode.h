#ifndef LEETCODE_H_
#define LEETCODE_H_

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
    return head;
}

void show_list(ListNode *head)
{
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout  << std::endl;
}

#endif  // LEETCODE_H
