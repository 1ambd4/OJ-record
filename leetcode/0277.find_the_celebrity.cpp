#include <iostream>
#include <vector>

using namespace std;

// 名流问题
// 定义出度为0，入度为n-1的节点为名流节点
// 判断有向图中是否存在名流节点
//
// 暴力法是O(n^2)
// 但判别一个节点不是名流节点比判别是名流节点要容易得多
// 因为有向图中若存在则仅可能存在一个名流节点
// 因而先找出可能的节点，然后仅仅判断这个节点就可以降到O(n)
int find_the_celebrity(vector<vector<int>>& graph)
{
    auto knows = [&graph](int a, int b) -> bool {
        return graph[a][b] == 1;
    };

    int n = graph.size()-1, cur = 0;

    for (int i = 0; i < n; ++i) {
        if (knows(cur,i)) {
            cur = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        // 判定不是要简单的多
        if (i != cur && (knows(cur,i) || !knows(i,cur))) {
            return -1;
        }
    }

    return cur;
}

int main()
{
    vector<vector<int>> graph { {1,1,1,0}, {1,1,1,1}, {0,0,1,0}, {0,0,1,1} };
    cout << find_the_celebrity(graph) << endl;
    return 0;
}

