#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int n;
    int temp;
    set<int> number;
    cin >> n;
    while(n--) {
        cin >> temp;
        number.insert(temp);
    }
    cout << number.size() << endl;
    set<int>::iterator beg = number.begin();
    set<int>::iterator ed = number.end();
    for (set<int>::iterator it = beg; it!= ed; it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}