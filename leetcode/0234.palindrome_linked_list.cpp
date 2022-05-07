#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* reverse_list(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *cur = head;
    head = reverse_list(head->next);
    cur->next->next = cur;
    cur->next = nullptr;
    return head;
}

bool is_palindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != nullptr) slow = slow->next;
    slow = reverse_list(slow);

    while (head != nullptr && slow != nullptr) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;
}

int main()
{
    vector<int> vec1 { 1, 2, 3, 2, 1 };
    ListNode *list1 = build_list(vec1)->next;
    cout << is_palindrome(list1) << endl;
    return 0;
}
