#include <iostream>
#include <vector>

using namespace std;

bool IsPowerOfThree(int n)
{
    // 3是质数，所以找到给定范围内最大的幂数，如果是其因数，则必定也是3的幂数
    return n > 0 && 1162261467 % n == 0;
}

int main(void)
{
    cout << IsPowerOfThree(27) << endl;
    cout << IsPowerOfThree(0) << endl;
    cout << IsPowerOfThree(9) << endl;
    cout << IsPowerOfThree(45) << endl;
    return 0;
}
