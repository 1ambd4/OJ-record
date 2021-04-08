#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int temp;
	vector<int> v;
	cin >> n;
	while (n--) {
		cin >> temp;
		v.push_back(temp);
	}
	vector<int>::iterator beg = v.begin();
	vector<int>::iterator ed = v.end();

	sort(beg, ed);
/* 	for (it : v) cout << it << " ";
	cout << endl; */

	vector<int>::iterator current = beg+1;
	vector<int>::iterator backup = current;

	int cnt = 1;
	for ( ;current != ed; ) {
		for ( ;*current == *backup; ) {
			current++;
			cnt++;
		}
		cout << *backup << " " << cnt;
		cnt = 1;
		backup = current;
		current++;
	}
	cout << "ok" << endl;
}