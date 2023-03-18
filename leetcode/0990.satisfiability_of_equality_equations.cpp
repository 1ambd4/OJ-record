#include <iostream>
#include <vector>

using namespace std;

bool equations_possible(vector<string>& equations)
{
    vector<int> parent(26);
    vector<int> size(26, 0);
    for (int i = 0; i < 26; ++i) parent[i] = i;

    auto find = [&parent, &size](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    };

    auto merge = [&parent, &size, &find](int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) return ;

        if (size[rx] > size[ry]) {
            parent[ry] = parent[rx];
            size[rx] += size[ry];
        } else {
            parent[rx] = parent[ry];
            size[ry] += size[rx];
        }

    };


    for (const auto& equation : equations) {
        if (equation[1] == '=') {
            merge(equation[0] - 'a', equation[3] - 'a');
        }
    }

    for (const auto& equation : equations) {
        if (equation[1] == '!') {
            if (find(equation[0] - 'a') == find(equation[3] - 'a')) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<string> equations1 {"a==b", "b!=a"};
    cout << equations_possible(equations1) << endl;

    vector<string> equations2 {"b==a", "a==b"};
    cout << equations_possible(equations2) << endl;
    return 0;
}

