#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }

    int val;
    ListNode *next;
};

// 老 408 原题了
ListNode* middle_node(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* build_list(vector<int> nums)
{
    ListNode *head = new ListNode();
    ListNode *cur = head;
    for (const int& num : nums) {
        ListNode *temp = new ListNode(num, nullptr);
        cur->next = temp;
        cur = cur->next;
    }
    return head;  
}

void show_list(ListNode *head)
{
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> case1 { 1, 2, 3, 4, 5, 6 };
    ListNode *head = build_list(case1);
    show_list(head->next);
    ListNode *ans1 = middle_node(head->next);
    show_list(ans1);
}
