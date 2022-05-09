#include <iostream>
#include <vector>
#include <climits>

#include "leetcode.h"

using namespace std;

ListNode* insertion_sort_list(ListNode *head)
{
    ListNode *dummy = new ListNode(INT_MIN), *cur = nullptr, *tmp = nullptr;

    while (head != nullptr) {
        cur = dummy;
        while (cur->next != nullptr && cur->next->val < head->val) {
            cur = cur->next;
        }
        tmp = head;
        head = head->next;
        tmp->next = cur->next;
        cur->next = tmp;
    }

    return dummy->next;
}

int main()
{
    vector<int> vec1 { 4, 2, 1, 3 };
    ListNode *list1 = build_list(vec1);
    cout << list1 << endl;
    ListNode *res1 = insertion_sort_list(list1);
    cout << res1 << endl;
    return 0;
}
