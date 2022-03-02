#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* reverse_list(ListNode *head)
{
    ListNode *dummy = new ListNode(0, nullptr), *cur;
    while (head != nullptr) {
        cur = head;
        head = head->next;
        cur->next = dummy->next;
        dummy->next = cur;
    }

    return dummy->next;
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 4, 5 };
    ListNode *case1 = build_list(nums1);
    ListNode *ans1 = reverse_list(case1->next);
    show_list(ans1);
    return 0;
}
