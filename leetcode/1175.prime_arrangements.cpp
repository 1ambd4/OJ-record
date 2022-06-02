#include <iostream>
#include <vector>

using namespace std;

// 1 ~ n
int num_prime_arrangements(int n)
{
    int nums_of_prime = [=]() -> int {
        int cnt = 0;
        vector<bool> prime(n+1, true);
        for (int i = 2; i * i <= n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) cnt++;
        }
        return cnt;
    }();

    int mod = 1e9 + 7;

    // 1既不是素数也不是和合数，但方便期间，统一和合数统计到非素数里去
    int nums_of_not_prime = n - nums_of_prime;

    long long int cnt = 1;
    for (int i = nums_of_not_prime; i > 0; --i) {
        cnt = cnt * i % mod;
    }
    for (int i = nums_of_prime; i > 0; --i) {
        cnt = cnt * i % mod;
    }

    return cnt;
}

int main()
{
    cout << num_prime_arrangements(5) << endl;
    cout << num_prime_arrangements(100) << endl;
    return 0;
}
