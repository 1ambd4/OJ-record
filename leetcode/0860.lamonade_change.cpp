#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lamonade_change(vector<int>& bills)
{
    int cnt[5] { 0 };
    for (const int bill : bills) {
        switch(bill) {
            case 5:
                ++cnt[0];
                break;
            case 10:
                ++cnt[1];
                if (cnt[0] > 0) --cnt[0];
                else return false;
                break;
            case 20:
                ++cnt[2];
                if (cnt[1] > 0 && cnt[0] > 0) {
                    --cnt[0];
                    --cnt[1];
                } else if (cnt[0] >= 3) {
                    cnt[0] -= 3;
                } else {
                    return false;
                }
                break;
        }
    }

    return true;
}

int main()
{
    vector<int> bills1 { 5, 5, 5, 10, 20 };
    cout << lamonade_change(bills1) << endl;

    vector<int> bills2 { 5, 5, 10, 10, 20 };
    cout << lamonade_change(bills2) << endl;

    vector<int> bills3 { 5, 5, 5, 20, 20, 20, 5, 5, 20, 5 };
    cout << lamonade_change(bills3) << endl;

    vector<int> bills4 { 5, 5, 5, 5, 20, 20, 5, 5, 5, 5 };
    cout << lamonade_change(bills4) << endl;

    vector<int> bills5 { 5, 5, 10, 10, 20 };
    cout << lamonade_change(bills5) << endl;
    return 0;
}
