#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
		int *p = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			p[i] = i+1;
		}
		do {
			for (int i = 0; i < n; i++) {
				cout << p[i];
			}
			cout << endl;
		} while (next_permutation(p, p+n));
	}
	return 0;
}


/* 题目描述：
    按从小到大的顺序输出 1, 2, 3, ..., N 所有的全排列

输入描述：
    每行输入一个整数 N

输出描述：
    无

样例输入：
3
4

样例输出：
123
132
213
231
312
321
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321 */