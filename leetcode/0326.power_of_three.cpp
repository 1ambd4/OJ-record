#include <iostream>
#include <vector>

using namespace std;

bool IsPowerOfThree(int n)
{
    vector<int> table = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
    auto it = find(table.begin(), table.end(), n);

    return it != table.end() ? true : false;
}

int main(void)
{
    cout << IsPowerOfThree(27) << endl;
    cout << IsPowerOfThree(0) << endl;
    cout << IsPowerOfThree(9) << endl;
    cout << IsPowerOfThree(45) << endl;
    return 0;
}
