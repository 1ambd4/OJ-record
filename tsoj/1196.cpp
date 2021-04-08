#include <iostream>
using namespace std;

int main(void) {
	int ans = 1;
	int n;
	while (cin >> n) {
		ans = 1;
		for (int i = 0; i <= n; i++) ans += i;
		cout << ans << endl;
	}
	return 0;
}


/* 题目描述:
在一个平面上有一个圆和 n 条直线，这些直线中每一条在圆内同其他直线相交，假设没有 3 条直线相交于一点，试问这些直线将圆分成多少区域。

输入描述：
每行一个整数，表示分割圆的直线条数

输出描述：
每行一个结果，表示划分圆的区域个数

样例输入:
1
2
3

样例输出:
2
4
7 */