#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> number;
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        number.push_back(temp);
    }
    vector<int>::iterator beg = number.begin();
    vector<int>::iterator ed = number.end();
    sort(beg, ed);
    for(vector<int>::iterator it = beg; it != ed; it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}