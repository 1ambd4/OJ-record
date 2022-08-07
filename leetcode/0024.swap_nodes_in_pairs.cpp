#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* swap_pairs(ListNode* head)
{
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    ListNode *prev = new ListNode(-1, head), *curr = head, *next = head->next;
    head = prev;

    while (prev != nullptr && prev->next != nullptr && prev->next->next != nullptr) {
        curr->next = next->next;
        prev->next = next;
        next->next = curr;

        prev = prev->next->next;
        curr = prev->next;
        if (curr == nullptr) {
            break;
        }
        next = curr->next;
    }

    return head->next;
}


ListNode* swap_pairs_(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *next = head->next;
    head->next = swap_pairs(next->next);
    next->next = head;

    return next;
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 4 };
    ListNode* list1 = build_list(nums1);
    cout << swap_pairs(list1) << endl;

    vector<int> nums2 { };
    ListNode* list2 = build_list(nums2);
    cout << swap_pairs(list2) << endl;

    vector<int> nums3 { 1 };
    ListNode* list3 = build_list(nums3);
    cout << swap_pairs(list3) << endl;
    return 0;
}

