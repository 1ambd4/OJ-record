#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
    int val;
    ListNode *next;
};

ListNode* add_two_numbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode(); // 头结点
    ListNode *cur = result;
    int sum = 0, carry = 0;
    while (l1 != nullptr && l2 != nullptr) {
        sum = l1->val + l2->val + carry;
        ListNode *node = new ListNode(sum % 10, nullptr);
        carry = sum / 10;
        cur->next = node;
        cur = cur->next;
        l1 = l1->next, l2 = l2->next;
    }
    // 至少有一个为空喽
    if(l1) {
        while (l1) {
            sum = l1->val + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l1 = l1->next;
        }
    } else if(l2) {
        while (l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l2 = l2->next;
        }
    }

    // 处理最后的进位部分
    if (l1 == nullptr && l2 == nullptr && carry) {
        cur->next = new ListNode(carry);
    }

    return result->next;
}

ListNode* build(vector<int> nums)
{
    ListNode *result = new ListNode(nums[0]);
    ListNode *cur = result;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode *temp = new ListNode(nums[i]);
        cur->next = temp;
        cur = cur->next;
    }
    return result;
}

void show(ListNode *l)
{
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main()
{
    vector<int> n1 = { 9, 9, 9, 9, 9, 9, 9 }; // { 2, 4, 3 };
    ListNode *l1 = build(n1);
    show(l1);

    vector<int> n2 = { 9, 9, 9, 9 }; // { 5, 6, 7, 2 };
    ListNode *l2 = build(n2);
    show(l2);

    ListNode *l3 = add_two_numbers(l1, l2);
    show(l3);
    return 0;
}
