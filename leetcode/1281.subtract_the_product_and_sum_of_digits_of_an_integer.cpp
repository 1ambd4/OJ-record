#include <iostream>
#include <vector>

using namespace std;

int subtract_product_and_sum(int n)
{
    int mul = 1, sum = 0;
    while (n) {
        mul *= n % 10;
        sum += n % 10;
        n /= 10;
    }
    return mul - sum;
}

int main()
{
    cout << subtract_product_and_sum(234) << endl;
    cout << subtract_product_and_sum(4421) << endl;

    return 0;
}

