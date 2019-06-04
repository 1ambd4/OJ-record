#include <iostream>
using namespace std;

int ans = 0;

void solve(int &a, int &b) {
	if (a > b) {
		a -= b;
		ans++;
	}
	else if (a < b){
		b -= a;
		ans++;
	}
	else {
		a -= b;
		ans++;
	}
}

int main(void) {
	int a, b;
	while (cin >> a >> b) {
		ans = 0;
		while(a >0 && b > 0) {
			solve(a, b);
		}
		cout << ans << endl;
	}
	return 0;
}


/* 题目描述:
修罗王与邪狼被关进监狱，该监狱的地下秩序实际上被不少黑暗势力所把持，这些黑暗势力根据其实力不同，划分出了大大小小的势力范围。具体为：监狱是一个给定的矩形，每一个黑暗势力的势力范围都必须是一个正方形，划分时，最大的黑暗势力尽可能多地从矩形中划一块正方形，接下来是第二大的黑暗势力在剩下的矩形中尽可能多地划分出一块正方形……

输入描述：
多组输入，每组两个整型数，表示矩形的长和宽

输出描述：
对应于每组数据，划分的正方形的个数

样例输入:
3 4

样例输出:
4 */