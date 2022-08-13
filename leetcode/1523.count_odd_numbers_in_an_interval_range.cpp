#include <iostream>
#include <vector>

using namespace std;

int count_odds(int low, int high)
{
    int delta = ((low&1) && (low&1)) ? 2 : 1;

    return (high - low + delta)>>1;
}

int main()
{
    cout << count_odds(3, 7) << endl;
    cout << count_odds(8, 10) << endl;
    return 0;
}

