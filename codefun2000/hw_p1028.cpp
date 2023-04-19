#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <unordered_map>
#include <algorithm>

int main()
{
#ifdef LOCAL
    freopen("hw_p1028.in", "r", stdin);
#endif
    std::string s;
    int k;
    while (std::cin >> s >> k) {
        int n = s.size();
        std::unordered_map<char, int> m;
        std::vector<char> v;

        for (int i{0}; i < n; ++i) {
            v.push_back(s[i]);
            // find太慢了
            // if (m.find(s[i]) == m.end()) {
            if (m[s[i]] <= 0) {
                m[s[i]] = i;
            }
        }
        m[s[0]] = 0;    // 防止m[s[0]]的下标被改动
        std::sort(v.begin(), v.end(), std::less<char>());
        if (k >= v.size()) {
            std::cout << m[v.back()] << std::endl;
        } else {
            std::cout << m[v[k-1]] << std::endl;
        }
    }
    return 0;
}

