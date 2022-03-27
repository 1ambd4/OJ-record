#include <iostream>

using namespace std;

// 机翻害人不浅呐
int guess_number(int n)
{
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right-left) / 2;
        if (guess(mid) == 0) {
            return mid;
        } else if (guess(mid) == -1) {
            right = mid - 1;
        } else if (guess(mid) == 1) {
            left = mid + 1;
        }
    }
}

int main()
{
    cout << guess_number(1) << endl;
    return 0;
}
