#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
	vector<int> arr;
		int temp, query;
		while (n--) {
			cin >> temp;
			arr.push_back(temp);
		}
		vector<int>::iterator beg = arr.begin();
		vector<int>::iterator ed = arr.end();
/* 		for (it : arr) cout << it << " ";
		cout << endl; */

		cin >> query;
		vector<int>::iterator iter = find(beg, ed, query);
		if (iter == arr.end()) {
			cout << "-1";
		}
		else {
			cout << distance(arr.begin(), iter)+1;
		}
		cout << endl;
	}

	return 0;
}



/* 题目描述:
    给出一个包含 n 个整数的数列，求出整数 a 在数列中的第一次出现的位置。

输入描述：
    每组测试数据包括三行。
    第一行包含一个整数 n（1 <= n <= 1000）。
    第二行包含 n 个非负整数，为给定的数列，数列中的每个数都不大于 10000。
    第三行包含一个整数 a，为待查找的数。

输出描述：
    如果 a 在数列中出现了，输出它第一次出现的位置 (位置从 1 开始编号)，否则输出 -1。

样例输入:
6
1 9 4 8 3 9
9
5
5 6 7 8 9
3

样例输出:
2
-1 */