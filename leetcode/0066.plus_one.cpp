#include <iostream>
#include <vector>

using namespace std;

vector<int> plus_one(vector<int>& digits)
{
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        int temp = digits[i] + carry;
        digits[i] = temp % 10;
        carry = temp / 10;
    }
    if (carry) {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

int main()
{
    vector<int> case1 { 1, 2, 3 };
    vector<int> rest1 = plus_one(case1);
    for (const int& num : rest1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> case2 { 9, 9, 9, 9 };
    vector<int> rest2 = plus_one(case2);
    for (const int& num : rest2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> case3 { 0 };
    vector<int> rest3 = plus_one(case3);
    for (const int& num : rest3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
