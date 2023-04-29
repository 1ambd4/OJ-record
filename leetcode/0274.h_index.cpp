#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

// h_index: h篇不低于h，其余n-h篇不超过h
// 那么就可以对cita进行排序
// 排序后，对于第i篇来说，n-i篇大于等于cita[i]，i篇小于等于cita[i]
// 令h=n-i，h篇不低于cita[i]，n-h篇不超过cita[a]
// 故而找到h<=cita[i]即可
int h_index(std::vector<int>& citations)
{
    int n = citations.size();
    std::sort(citations.begin(), citations.end());

    for (int i = 0; i < n; ++i) {
        int h = n - i;
        if (h <= citations[i]) {
            return h;
        }
    }
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("0274.in", "r", stdin);
#endif

    int n = 0;
    while (std::cin >> n) {
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) std::cin >> v[i];
        std::cout << h_index(v) << std::endl;
    }

    return 0;
}

