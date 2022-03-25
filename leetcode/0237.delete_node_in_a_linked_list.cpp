#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void delete_node(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
    return;
}

int main()
{
    vector<int> vec1{4,5,1,9};
    ListNode *list1 = build_list(vec1), *node;
    show_list(list1);
    node = list1->next->next;
    delete_node(node);
    show_list(list1);
    return 0;
}
