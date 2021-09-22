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
    vector<ListNode*> lists_after_split;
    ListNode *current = head;
    while (current != nullptr) {
        length_of_original_list++;
        current = current->next;
    }

    // 说了任意两部分的长度差距不超过1，那么只可能存在二值
    // 要么size/k，要么在其基础上加1，方便其间，将每个链表的长度保存起来
    
    vector<int> length_of_each_list(k, length_of_original_list / k);
    for (int i = 0; i < length_of_original_list % k; ++i) {
        length_of_each_list[i]++;
    }

    // 不管怎么说，最后需要创建k个链表啊
    for (int i = 0; i < k; ++i) {
        if (length_of_each_list[i] == 0) {
            lists_after_split.push_back(nullptr);
            continue;
        }

        ListNode *temp_head = new ListNode(head->val, nullptr);
        current = temp_head;
        head = head->next;
        for (int j = 1; j < length_of_each_list[i]; ++j) {
            ListNode  *temp = new ListNode(head->val, nullptr);
            head = head->next;
            current->next = temp;
            current = temp;
        }
        
        lists_after_split.push_back(temp_head);
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
