#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

constexpr int N = 11111111 + 10;

// MLE
// int main()
// {
//     int n, a, b;
//     vector<unsigned long long> nums(N, 0);
//     while (cin >> n) {
//         for (int i = 0; i < n; ++i) {
//             cin >> a >> b;
//             nums[a] += b;
//         }
//         for (int i = 0; i < N; ++i) {
//             if (nums[i] != 0) {
//                 cout << i << " " << nums[i] << endl;
//             }
//         }
//     }
//     return 0;
// }

int main()
{
    int n, a, b;
    using pii = pair<int, unsigned long long>;
    unordered_map<int, unsigned long long> m;
    while (cin >> n) {
        m.clear();
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            m[a] += b;
        }
        vector<pii> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pii& a, pii& b) -> bool {
                return a.first < b.first;
        });
        for (const auto& [i, k] : v) {
            cout << i << " " << k << endl;
        }
    }
    return 0;
}
