#include <iostream>

#include "leetcode.h"

using namespace std;

bool has_cycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr || fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}


// 快慢指针判断链表是否有环
bool _has_cycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    do {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    return true;
}

int main()
{
    vector<int> nums1 { 3, 2, 0, -4 };
    ListNode *case1 = build_list(nums1);
    case1->next->next->next->next = case1->next;
    cout << has_cycle(case1) << endl;

    return 0;
}
