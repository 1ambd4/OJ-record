#include <iostream>

using namespace std;

bool is_palindrome(int x)
{
    if (x < 0) return false;

    int rx = 0, tx = x;
    while (tx > 0) {
        rx = rx * 10 + tx % 10;
        tx /= 10;
    }

    return rx == x;
}

int main()
{
    cout << is_palindrome(121) << endl;
    cout << is_palindrome(-121) << endl;
    cout << is_palindrome(1) << endl;
    cout << is_palindrome(0) << endl;
    cout << is_palindrome(1234567899) << endl;
    return 0;
}
