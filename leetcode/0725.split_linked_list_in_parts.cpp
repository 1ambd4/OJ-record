#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
public:
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }

    int val;
    ListNode *next;
};

// 日常读不懂题，我以为不能改变原链表
// 那可以不用新创建链表，将链表打断
vector<ListNode*> SplitListToParts(ListNode *head, int k)
{
    int length_of_original_list = 0;
    vector<ListNode*> lists_after_split(k, nullptr);
    ListNode *curr = head, *temp = nullptr;
    while (curr != nullptr) {
        length_of_original_list++;
        curr = curr->next;
    }

    // 说了任意两部分的长度差距不超过1，那么只可能存在二值
    vector<int> length_of_each_list(k, length_of_original_list / k);
    for (int i = 0; i < length_of_original_list % k; ++i) {
        length_of_each_list[i]++;
    }

    curr = head;
    for (int i = 0; i < k && curr != nullptr; ++i) {

        lists_after_split[i] = curr;

        for (int j = 1; j < length_of_each_list[i]; ++j) {
            curr = curr->next;
        }

        temp = curr->next;
        curr->next = nullptr;
        curr = temp;
    }

    return lists_after_split;
}

void PrintList(ListNode *head)
{
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
};

ListNode* BuildList(vector<int> v)
{
    ListNode *head = new ListNode(), *p = head, *temp = nullptr;
    for (const auto &e : v) {
        temp = new ListNode(e, nullptr); 
        p->next = temp;
        p = temp;
    }
    return head;
}

int main(void)
{
    vector<int> first_test_case {1, 2, 3};
    ListNode *first_test_list_head = BuildList(first_test_case);
    vector<ListNode*> first_list_after_split = SplitListToParts(first_test_list_head->next, 5);
    for (auto e : first_list_after_split) {
        PrintList(e);
    }

    vector<int> second_test_case {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // {1, 2, 3};
    ListNode *second_test_list_head = BuildList(second_test_case);
    vector<ListNode*> second_list_after_split = SplitListToParts(second_test_list_head->next, 3);
    for (auto e : second_list_after_split) {
        PrintList(e);
    }

    return 0;
}
