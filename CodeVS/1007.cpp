#include <iostream>
using namespace std;

int main(void)
{
    int k = 0;
    double s = 0;
    cin >> k;
    int i;
    for (i = 1; s < k; i++) {
        s += 1.0/i;
    }
    cout << i-1 << endl;
    return 0;
}