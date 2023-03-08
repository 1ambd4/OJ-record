#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* detect_cycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    do {
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


ListNode* _detect_cycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (fast == nullptr || fast->next == nullptr) return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    vector<int> nums1 { 3, 2, 0, -4 };
    ListNode *case1 = build_list(nums1);
    case1->next->next->next->next = case1->next;
    ListNode *res1 = detect_cycle(case1);
    if (res1 != nullptr) {
        cout << res1->val << endl;
    } else {
        cout << "no cycle" << endl;
    }

    return 0;
}

