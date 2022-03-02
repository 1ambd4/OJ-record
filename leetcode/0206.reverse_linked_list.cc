#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* reverse_list(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *ret = reverse_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ret;
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 4, 5 };
    ListNode *case1 = build_list(nums1);
    ListNode *ans1 = reverse_list(case1->next);
    show_list(ans1);
    return 0;
}
