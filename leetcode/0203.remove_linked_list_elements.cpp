#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// 放回删除一个val后的链表
ListNode* remove_elements(ListNode *head, int val)
{
    if (head == nullptr) {
        return head;
    }

    head->next = remove_elements(head->next, val);

    return head->val == val ? head->next : head;
}

int main()
{
    vector<int> nums { 1, 2, 3, 4, 5, 6 };
    ListNode *case1 = build_list(nums);
    show_list(case1);
    ListNode *ans1 = remove_elements(case1->next, 6);
    show_list(ans1);
    return 0;
}
