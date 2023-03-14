#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() { }

    Node(int val) : val(val) { }

    Node(int val, vector<Node*> child) : val(val), children(child) { }
};

Node* build(vector<int> nums)
{
    int n = nums.size();
    if (n == 0) return nullptr;

    Node *root = new Node(nums.front()), *cur = root;
    queue<Node*> q;
    q.push(cur);

    for (int i = 1; i < n; ++i) {
        if (nums[i] == -1) {
            cur = q.front();
            q.pop();
        } else {
            Node *tmp = new Node(nums[i]);
            cur->children.push_back(tmp);
            q.push(tmp);
        }
    }

    return root;
}

void show(Node *root)
{
    auto traverse = [](auto&& self, Node *root) {
        if (root == nullptr) return ;
        cout << root->val << " ";

        for (const auto& child : root->children) {
            self(self, child);
        }
    };

    traverse(traverse, root);
    cout << endl;
}

int max_depth(Node *root)
{
    int res = 0;
    if (root == nullptr) return res;

    queue<Node*> q;
    q.push(root);
    Node *cur = nullptr;

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; ++i) {
            cur = q.front();
            q.pop();
            for (const auto& child : cur->children) {
                q.push(child);
            }
        }
        ++res;
    }

    return res;
}

int _max_depth(Node *root)
{
    int res = 0, depth = 0;

    auto traverse = [&res, &depth](auto&& self, Node *root) -> void {
        if (root == nullptr) return ;

        ++depth;
        res = max(res, depth);
        for (const auto& child : root->children) {
            self(self, child);
        }
        --depth;
    };

    traverse(traverse, root);
    return res;
}

int __max_depth(Node *root)
{
    if (root == nullptr) return 0;

    int depth = 0;
    for (const auto& child : root->children) {
        depth = max(depth, max_depth(child));
    }

    return 1 + depth;
}

int main()
{
    vector<int> nums1 {1,-1,3,2,4,-1,5,6};
    Node *tree1 = build(nums1);
    show(tree1);
    cout << max_depth(tree1) << endl;

    vector<int> nums2 {1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14};
    Node *tree2 = build(nums2);
    show(tree2);
    cout << max_depth(tree2) << endl;

    return 0;
}

