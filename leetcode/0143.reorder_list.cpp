#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* find_middle_node(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode *head)
{
    ListNode *pre = nullptr, *cur = head, *nxt = nullptr;

    while (cur != nullptr) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

void merge(ListNode *l1, ListNode *l2)
{
    ListNode *nl1 = nullptr, *nl2 = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        nl1 = l1->next;
        nl2 = l2->next;

        l1->next = l2;
        l1 = nl1;
        l2->next = l1;
        l2 = nl2;
    }
}

void reorder_list(ListNode *head)
{
    ListNode *l1 = head, *l2 = nullptr;
    ListNode *m = find_middle_node(head);
    l2 = m->next;
    m->next = nullptr;
    l2 = reverse(l2);
    merge(l1, l2);
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 4 };
    ListNode *list1 = build_list(nums1);
    cout << list1 << endl;
    reorder_list(list1);
    cout << list1 << endl;
    return 0;
}

