#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

ListNode* get_intersection_node(ListNode *ha, ListNode *hb)
{
    ListNode *la = ha, *lb = hb;
    while (la != lb) {
        if (la == nullptr) la = hb;
        else la = la->next;

        if (lb == nullptr) lb = ha;
        else lb = lb->next;
    }

    return la;
}

ListNode* _get_intersection_node(ListNode *head_a, ListNode *head_b)
{
    ListNode *la = head_a, *lb = head_b;
    while (la != lb) {
        if (la == nullptr) {
            la = head_b;
        } else {
            la = la->next;
        }
        if (lb == nullptr) {
            lb = head_a;
        } else {
            lb = lb->next;
        }
    }
    return la;
}

int main()
{
    vector<int> vec1 { 4, 1, 8, 4, 5 }, vec2 { 5, 6, 1, 8, 4, 5 };
    ListNode *list1 = build_list(vec1), *list2 = build_list(vec2);
    ListNode *res1 = get_intersection_node(list1->next, list2->next);
    show_list(list1->next);
    show_list(list2->next);
    show_list(res1);

    return 0;
}
