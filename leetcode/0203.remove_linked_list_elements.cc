#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* _remove_elements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(-1, head), *pre = dummy, *cur = head;
    while (cur != nullptr) {
        if (cur->val != val) {
            pre = pre->next;
        } else {
            while (cur != nullptr && cur->val == val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = cur;
        }
        cur = cur != nullptr ? cur->next : cur;
    }
    return dummy->next;
}

ListNode* remove_elements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(-1, head), *cur = dummy;
    while (cur->next != nullptr) {
        cur->next->val == val ? cur->next = cur->next->next : cur = cur->next;
        // if (cur->next->val == val) {
        //     cur->next = cur->next->next;
        // } else {
        //     cur = cur->next;
        // }
    }
    return dummy->next;
}

int main()
{
    vector<int> nums { 1, 2, 3, 4, 5, 6 };
    ListNode *case1 = build_list(nums);
    show_list(case1);
    ListNode *ans1 = remove_elements(case1->next, 6);
    show_list(ans1);
    return 0;
}
