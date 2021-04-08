#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void) {
	freopen("in.txt", "r", stdin);
	int n, key = 0;
	string cm = "China";
	vector<string> v;
	string name;
	while (cin >> n) {
		v.clear();
		while (n--) {
			cin >> name;
			v.push_back(name);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (v[i] != cm)	cout << v[i] << endl;
			else key = i;
		}
		cout << v[key] << endl;
	}
	return 0;
}