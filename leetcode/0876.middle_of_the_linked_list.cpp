#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* middle_node(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main()
{
    vector<int> case1 { 1, 2, 3, 4, 5, 6 };
    ListNode *head = build_list(case1);
    show_list(head->next);
    ListNode *ans1 = middle_node(head->next);
    show_list(ans1);

    return 0;
}
