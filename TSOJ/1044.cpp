#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10];
vector<int> a, b;

bool cmp(const int a, const int b) {
	return a > b;
}
int main(void) {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0) {
			a.push_back(arr[i]);
		}
		else {
			b.push_back(arr[i]);
		}
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end());
	for (it : a) cout << it << " ";
	for (it : b) cout << it << " "; cout << endl;
}