#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
	int t = 10;
	ll num, ans = 0;
	while (t--) {
		cin >> num;
		ans += num;
	}
	cout << ans << endl;
	return 0;
}


/* 题目描述:
    给出十个整数，求其和并输出，十个数均小于 10 ^ 7。（ int 类型不合适的话用 long 类型试试）

输入描述：
    十个整数。

输出描述：
    一个整数，为十个整数的和。

样例输入:
3
3
9
13
8
9
10
0
1
2

样例输出:
58 */