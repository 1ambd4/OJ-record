#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left, *right, *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) { }
    Node(int val) : val(val), left(nullptr), right(nullptr), next(nullptr) { }
    Node(int val, Node *left, Node *right, Node *next)
        : val(val), left(left), right(right), next(next) { }
};

Node* build_tree(std::vector<int>& nums)
{
    if (nums.size() == 0) return nullptr;

    Node *head = new Node(nums[0]), *cur = head, *temp;
    std::queue<Node*> q;
    q.push(cur);
    for (int i = 1; i < nums.size(); i += 2) {
        cur = q.front();
        q.pop();
        if (i < nums.size()) {
            if (nums[i] != -1) {
                temp = new Node(nums[i]);
                cur->left = temp;
                q.push(temp);
            } else {
                cur->left = nullptr;
            }
        }
        if (i+1 < nums.size()) {
            if (nums[i+1] != -1) {
                temp = new Node(nums[i]);
                cur->right = temp;
                q.push(temp);
            } else {
                cur->right = nullptr;
            }
        }
    }
    return head;
}

// 层次遍历
void traversal(Node *root)
{
    if (root == nullptr) return;
    queue<Node*> q;
    Node *cur;
    q.push(root);
    cout << root->val << ' ';
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        while (cur != nullptr) {
            cout << cur->val << ' ';
            cur = cur->next;
        }
    }
    cout << endl;
}

void connect(Node *node1, Node *node2)
{
    if (node1 == nullptr || node2 == nullptr) return ;

    node1->next = node2;

    connect(node1->left, node1->right);
    connect(node2->left, node2->right);
    connect(node1->right, node2->left);
}

Node* connect(Node *root)
{
    if (root == nullptr) return nullptr;
    connect(root->left, root->right);
    return root;
}

int main()
{
    vector<int> vec1 {1,2,3,4,5,6,7};
    Node *tree1 = build_tree(vec1);
    Node *res1 = connect(tree1);
    traversal(res1);
    return 0;
}
