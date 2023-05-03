#include <iostream>
#include <iterator>
#include <vector>

#include "../leetcode.h"

using namespace std;

void reverse_print(ListNode *head, vector<int> &res);

std::vector<int> reverse_print(ListNode *head)
{
    std::vector<int> res;

    auto traverse = [&res](auto&& self, ListNode *cur) -> void {
        if (cur == nullptr) return ;

        self(self, cur->next);
        res.push_back(cur->val);
    };

    return res;
}

// vector<int> reverse_print(ListNode *head)
// {
//     vector<int> res;
//
//     reverse_print(head, res);
//
//     return res;
// }
//
// void reverse_print(ListNode *head, vector<int> &res)
// {
//     if (head == nullptr) {
//         return ;
//     }
//
//     reverse_print(head->next, res);
//     res.push_back(head->val);
// }

int main()
{
    ostream_iterator<int> out_iter(cout, " ");

    vector<int> case1 {1, 3, 2};
    ListNode *list1 = build_list(case1);
    show_list(list1->next);
    vector<int> res1 = reverse_print(list1->next);
    copy(res1.begin(), res1.end(), out_iter);
    cout << endl;

    vector<int> case2 { };
    ListNode *list2 = build_list(case2);
    show_list(list2->next);
    vector<int> res2 = reverse_print(list2->next);
    copy(res2.begin(), res2.end(), out_iter);
    cout << endl;

    return 0;
}
