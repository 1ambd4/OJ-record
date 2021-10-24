#include <iostream>

#include "listnode.h"

using namespace std;

ListNode* remove_nth_from_end(ListNode *head, int n)
{
    // 双指针，为了方便删除结点，让left再慢于right一步
    // 但如果让right多走一步，得处理nullptr的情况，那不如让left退一步
    ListNode *left = new ListNode(0, head), *right = head;

    while (n--) {
        right = right->next;
    }
    if (right == nullptr && n == -1) {
        return head->next;
    }
    while (right != nullptr) {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;

    return head;
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 4, 5 };
    ListNode *case1 = build_list(nums1);
    show_list(remove_nth_from_end(case1->next, 2));

    vector<int> nums2 { 1, 2 };
    ListNode *case2 = build_list(nums2);
    show_list(remove_nth_from_end(case2->next, 1));
    return 0;
}
