#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

// 相较于有序链表合并的区别仅仅是每次比较2个数扩展到每次比较k个数
// 那么比较显然是不合适的，时间复杂度太高
// 注意到每次k个数只有一个会被选出来加入到结果链表中
// 很自然的想到用有限队列维护待插入数据
ListNode* merge_k_lists(vector<ListNode*>& lists)
{
    ListNode *dummy = new ListNode(-1, nullptr), *cur = dummy;

    auto cmp = [](ListNode *a, ListNode *b) -> bool {
        return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

    for (const auto& head : lists) {
        if (head != nullptr) pq.push(head);
    }

    while (!pq.empty()) {
        ListNode *tmp = pq.top(); pq.pop();
        cur->next = tmp;
        cur = cur->next;
        if (tmp->next != nullptr) pq.push(tmp->next);
    }

    return dummy->next;
}

int main()
{
    vector<ListNode*> lists1;
    lists1.push_back(build_list({1,4,5}));
    lists1.push_back(build_list({1,3,4}));
    lists1.push_back(build_list({2,6}));
    ListNode *res1 = merge_k_lists(lists1);
    show_list(res1);

    return 0;
}

