#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* _delete_publicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0, head), *left = head, *right = head;
    while (right != nullptr) {
        right = right->next;
        while (right != nullptr && left->val == right->val) {
            right = right->next;
        }
        left->next = right;
        left = right;
    }
    return dummy->next;
}

ListNode* delete_publicates(ListNode *head)
{
    ListNode *cur = head;
    while (cur->next != nullptr) {
        cur->next->val == cur->val ? cur->next = cur->next->next : cur = cur->next;
    }
    return head;
}

int main()
{
    vector<int> nums1 { 1, 1, 2, 2, 2, 2 };
    ListNode *case1 = build_list(nums1);
    ListNode *ans1 = delete_publicates(case1->next);
    show_list(ans1);
    return 0;
}
