#include <iostream>

using namespace std;

// 这题不就是统计二进制表示是否只有一个1么
bool _is_power_of_two(int n)
{
    return n > 0 && (n & (n-1)) == 0;
}

bool is_power_of_two(int n)
{
    const int MAX = 1<<30;
    return n > 0 && MAX % n == 0;
}

int main()
{
    cout << is_power_of_two(1) << endl;
    cout << is_power_of_two(2) << endl;
    cout << is_power_of_two(3) << endl;
    cout << is_power_of_two(4) << endl;
    cout << is_power_of_two(5) << endl;
    return 0;
}
