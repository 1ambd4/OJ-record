#include <iostream>

#include "leetcode.h"

using namespace std;

ListNode* merge_two_lists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(), *cur = dummy;
    while (l1 != nullptr && l2 != nullptr) {
        // 小 trick，前不久才看到 linus 这么写过
        ListNode **temp = (l1->val < l2->val) ? &l1 : &l2;
        cur->next = *temp;
        cur = cur->next;
        *temp = (*temp)->next;

//        if (l1->val < l2->val) {
//            cur->next = l1;
//            cur = cur->next;
//            l1 = l1->next;
//        } else {
//            cur->next = l2;
//            cur = cur->next;
//            l2 = l2->next;
//        }
    }

    cur->next = l1 != nullptr ? l1 : l2;

    return dummy->next;
}

int main()
{
    vector<int> nums1 { 1, 2, 4 }, nums2 { 1, 3, 4 };
    ListNode *l1 = build_list(nums1);
    ListNode *l2 = build_list(nums2);
    ListNode *ans1 = merge_two_lists(l1, l2);
    show_list(ans1);

    return 0;
}
