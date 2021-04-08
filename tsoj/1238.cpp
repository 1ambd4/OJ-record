#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(void) {
	int n;
	while (cin >> n) {
		int k, bk, temp, value = 0;
		while (n--) {
			cin >> k;
			bk = k;
			v.clear();
			while (k--) {
				cin >> temp;
				v.push_back(temp);
			}
			sort(v.begin(), v.end());
			value += v.at(bk - 1);
		}
		cout << value << endl;
	}
	return 0;
}



/* 题目描述:
    经过九九八十一难，唐僧和他徒弟们终于到了西天。幽静的雷音寺中包含了 n 个房间，每个房间中 k 本经书，每本经书都有一定的价值。由于时间限制，每个房间只够拿一本经书，很显然，肯定拿那本价值最大的经书。

输入描述：
    输入数据的第一行是房间数 n。接下来的 n 行每行描述了房间的经书情况：第一个数是经书的本数 k，然后是 k 个整数，表示每一本经书的价值。

输出描述：
    占一行，唐僧他们总共能拿到经书的最大价值（在 long 范围以内）。

样例输入:
4
3 2 2 5
5 3 3 4 4 1
2 30 23
5 10 20 30 20 30

样例输出:
69 */