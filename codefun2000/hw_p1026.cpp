#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>

int main()
{
#ifdef LOCAL
    freopen("./hw_p1026.in", "r", stdin);
#endif
    using pci = std::pair<char, int>;
    std::string s;
    int a, b;
    while (std::cin >> a >> b >> s) {
        int n = s.size();
        std::unordered_map<char, int> m;

        for (int i{0}; i < n; ++i) {
            ++m[s[i]];
            if ((i+1) % b == 0) {
                // std::vector<std::pair<char, int>> v(m);
                std::vector<pci> v(m.begin(), m.end());
                std::sort(v.begin(), v.end(), [](pci& a, pci& b) -> bool {
                        return a.second == b.second ? a.first > b.first : a.second > b.second;
                });
                for (int j = 0; j < a; ++j) {
                    std::cout << v[j].first;
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
