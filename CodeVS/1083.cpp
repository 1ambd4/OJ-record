#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> vec;
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        vec.push_back(temp);
    }
    vector<int>::iterator beg = vec.begin();
    vector<int>::iterator ed = vec.end();

    //Ｃ＋＋17的优雅遍历容器
    for (it: vec) {
        cout << it << " ";
    }
    cout << endl;

    //反向遍历容器
    for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //和vec[5]用法相同
    cout << vec.at(5) << endl;

    cout << vec.size() << endl;

    cout << vec.empty() << endl;

    vec.clear();

    for (it: vec) {
        cout << it << " ";
    }
    cout << endl;

    cout << vec.capacity() << endl;

    return 0;
}