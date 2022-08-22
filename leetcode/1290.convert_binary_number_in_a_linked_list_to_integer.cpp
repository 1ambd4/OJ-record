#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

int get_decimal_value(ListNode* head)
{
    int res = 0;
    while (head != nullptr) {
        res = (res<<1) + head->val;
        head = head->next;
    }
    return res;
}

int main()
{
    vector<int> nums1 { 1, 0, 1 };
    ListNode* list1 = build_list(nums1);
    cout << get_decimal_value(list1) << endl;

    vector<int> nums2 { 0 };
    ListNode* list2 = build_list(nums2);
    cout << get_decimal_value(list2) << endl;

    vector<int> nums3 { 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
    ListNode* list3 = build_list(nums3);
    cout << get_decimal_value(list3) << endl;
    return 0;
}

