#include <iostream>

using namespace std;

bool is_three(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            cnt += 2;
            if (i == n / i) --cnt;
        }
    }

    return cnt == 3;
}

int main()
{
    cout << is_three(2) << endl;
    cout << is_three(4) << endl;
    cout << is_three(38) << endl;
    return 0;
}
