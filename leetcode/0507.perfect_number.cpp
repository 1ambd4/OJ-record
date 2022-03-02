#include <iostream>
#include <cmath>

using namespace std;

bool check_perfect_number(int num)
{
    if (num == 1) return false;
    int e = sqrt(num), n = num - 1;
    for (int i = 2; i <= e; ++i) {
        if (num % i == 0) {
            n -= i;
            n -= num/i;
        }
    }

    return n == 0;
}

int main()
{
    cout << check_perfect_number(2) << endl;
    cout << check_perfect_number(496) << endl;
    cout << check_perfect_number(8128) << endl;
    return 0;
}
