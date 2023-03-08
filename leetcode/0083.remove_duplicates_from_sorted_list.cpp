#include <iostream>

#include "leetcode.h"

using namespace std;

// 大概就是line 33算法的简化版，省去了一个指针
ListNode* delete_duplicates(ListNode *head)
{
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        cur->next->val == cur->val ? cur->next = cur->next->next : cur = cur->next;
    }
    return head;
}

ListNode* _delete_duplicates(ListNode *head)
{
    if (head == nullptr) return nullptr;

    ListNode *dummy = new ListNode(-1, head), *slow = head, *fast = head;
    while (fast != nullptr) {
        fast = fast->next;
        while (fast != nullptr && fast->val == slow->val) {
            fast = fast->next;
        }
        slow->next = fast;
        slow = slow->next;
    }
    return dummy->next;
}

ListNode* __delete_duplicates(ListNode *head)
{
    if (head == nullptr) return nullptr;

    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        if (fast->val != slow->val) {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = nullptr;

    return head;
}

ListNode* ___delete_duplicates(ListNode *head)
{
    if (head == nullptr) return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        if (fast->val != slow->val) {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }

    slow->next = nullptr;
    return head;
}

int main()
{
    vector<int> vec1 {1,1,2};
    ListNode *l1 = build_list(vec1);
    delete_duplicates(l1);
    show_list(l1);

    vector<int> vec2 {1,1,2,3,3};
    ListNode *l2 = build_list(vec2);
    delete_duplicates(l2);
    show_list(l2);

    return 0;
}
