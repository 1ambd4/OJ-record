#include <iostream>
#include <stack>

#include "listnode.h"

using namespace std;

ListNode* remove_nth_from_end(ListNode *head, int n)
{
    // 利用栈保存欲删除结点的前驱
    ListNode *dummy = new ListNode(0, head);
    stack<ListNode*> s;

    ListNode *cur = dummy;
    while (cur) {
        s.push(cur);
        cur = cur->next;
    }
    for (int i = 0; i < n; ++i) {
        s.pop();
    }
    ListNode *pre = s.top();
    pre->next = pre->next->next;

    return dummy->next;
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
