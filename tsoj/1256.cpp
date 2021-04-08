#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void solve(int *p, int *q, int lenth) {

}

int main(void) {
	freopen("in.txt", "r", stdin);
	int m, n, c, temp;
	vector<int> boy, girl;
	while (cin >> m >> n >> c) {
		boy.clear();
		girl.clear();
		while (m--) {
			cin >> temp;
			boy.push_back(temp);
		}
		while (n--) {
			cin >> temp;
			girl.push_back(temp);
		}
		sort(boy.begin(), boy.end());
		sort(girl.begin(), girl.end());
		//for (it : boy) cout << it << " "; cout << endl;
		//for (it : girl) cout << it << " "; cout << endl;
		if (m > n) {
			//solve()
		}
	}
	return 0;
}