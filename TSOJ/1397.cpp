#include <iostream>
#include <set>
#include <iterator>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
/* 	//freopen("in.txt", "r", stdin);
	int n, t;
	set<int> s;
	while(cin >> n) {
		s.clear();
		while (n--) {
			cin >> t;
			s.insert(t);
		}
		set<int>::iterator beg = s.begin();
		set<int>::iterator ed = s.end();
		cout << s.size() << endl;
		for (set<int>::iterator it = beg; it != ed; it++) {
			cout << *it << " ";
		}
		cout << endl;
	} */

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, bn, t;
	vector<int> v;
	while(cin >> n) {
		bn = n -1; 
		v.clear();
		while (n--) {
			cin >> t;
			v.push_back(t);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		cout << v.size() << endl;
/* 		for (it : v) cout << it << " ";
		cout << endl; */
		for (int i = 0; i < v.size(); i++) cout << v.at(i) << " ";
		cout << endl;
	}
	return 0;
}