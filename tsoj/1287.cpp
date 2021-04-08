#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	//while (cin >> n) {
		vector<int> v;
		int temp, bk = n;
		while (n--) {
			cin >> temp;;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		cout << v.front() << endl;
	//}
	return 0;
}