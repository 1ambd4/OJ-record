#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
{
    // 递归的终点是某一个链表为空
    if (l1 == nullptr)
    {
        return l2;
    }
    else if (l2 == nullptr)
    {
        return l1;
    }

    // 如果都不为空，则比较节点值大小，将值大的合并到值小的链表后
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next =  mergeTwoList(l2->next, l1);
        return l2;
    }
}

int main(void)
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(3);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(9);

    ListNode *res = mergeTwoList(l1, l2);

    while (res != nullptr)
    {
        cout << res->val << ", ";
        res = res->next;
    }

    return 0;
}
