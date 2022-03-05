#include <iostream>

#include "leetcode.h"

using namespace std;

ListNode* delete_duplicates(ListNode *head)
{
    if (head == nullptr) return nullptr;
    ListNode *left = head, *right = head;
    while (right != nullptr) {
        if (right->val != left->val) {
            left->next = right;
            left = left->next;
        }
        right = right->next;
    }

    left->next = nullptr;
    return head;
}

int main()
{
    vector<int> vec1 { 1,1,2 };
    ListNode *l1 = build_list(vec1);
    delete_duplicates(l1);
    show_list(l1);
    return 0;
}
