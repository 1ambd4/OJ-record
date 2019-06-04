#include <iostream>
using namespace std;

long long turn = 0, t = 0;

void hanoi(int n) {
	if (n == 1) turn++, t++;
	else {
		hanoi(n-1);
		turn = turn * 2 +1;
		t = t * 2 + n;
	}
}

int main(void) {
	int n;
	bg:
	while (cin >> n) {
		if (n == 64) {
			cout << "18446744073709551615" << endl;
			goto bg;
		}
		turn = 0;
		hanoi(n);
		cout << turn << endl;
	}
	return 0;
}


//http://blog.csdn.net/m0_38033475/article/details/79335112