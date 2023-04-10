#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    while (cin >> n) {
        int N = n;
        // 类似欧拉筛的思想，每次把最小的素数因子除干净
        for (int i = 2; i <= N / i + 1 && n >= i; ++i) {
            while (n % i == 0) {
                printf("%d ", i);
                n /= i;
            }
        }
        if (n - 1) printf("%d", n);
        putchar('\n');
    }
    return 0;
}
