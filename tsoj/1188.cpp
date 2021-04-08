#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
 
int main(void) {
	for (int i = 0; i < 100000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0) ) v.push_back(i);
	}
	
	int n;
	while (cin >> n) {
		cout << v.at(n) << endl;
	}

	return 0;
}