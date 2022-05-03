class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> res;

            if (root == nullptr) return res;

            queue<Node*> q;
            Node *cur = nullptr;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();

                res.push_back(vector<int>());

                for (int i = 0; i < size; ++i) {
                    cur = q.front();
                    q.pop();
                    res.back().push_back(cur->val);
                    for (const auto& e : cur->children) {
                        q.push(e);
                    }
                }
            }

            return res;
        }
};
