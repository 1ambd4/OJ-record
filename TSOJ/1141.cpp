#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	freopen("in.txt", "r", stdin);
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char a;
	string s;
	
	while (cin >> a) {
		int t = a - 'A';
		if (t >= 0 && t <= 26) {
			cout << alphabet[(t+5)%26] <<" ";
		}
		else {
			cout << a <<" ";
		}
	}
	cout << endl;
	return 0;
}