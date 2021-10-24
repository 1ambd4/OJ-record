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

ListNode* middle_node(ListNode *head)
{
    int len = 0;
    ListNode *cur = head;
    while (cur != nullptr) {
        ++len;
        cur = cur->next;
    }
    
    len /= 2;
    while (len--) {
        head = head->next;
    }

    return head;    
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
