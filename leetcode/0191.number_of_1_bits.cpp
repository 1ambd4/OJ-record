#include <iostream>

using namespace std;

int hamming_weight_(uint32_t n)
{
    int count = 0;
    while(n) {
        if (n&1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int hamming_weight(uint32_t n)
{
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}

int main()
{
    uint32_t case1 = 15; // 00000000000000000000000000001011L;
    cout << hamming_weight(case1) << endl;

    return 0;
}
