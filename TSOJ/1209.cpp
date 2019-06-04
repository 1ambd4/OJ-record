#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if(n < 2) return 0;
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2; i < m; i++)
        if(n%i == 0) return 0;
    return 1;
}

int main(void) {
	int n;
	bg:
	while (cin >> n) {
		for (int i = n; i > 5; i--) {
			if (is_prime(i) && is_prime(i-2))  {
				cout << i - 2 << " " << i << endl;
				goto bg;
			}
		}
	}
	return 0;
}


/* 题目描述:
    如果 m 和 m + 2 都是素数，则称它们是孪生素数。输入一些正整数 m，输出两个数均不超过 m 的最大孪生素数。

输入描述：
    一些正整数 m (5 <= m <= 10000)，每个占一行。

输出描述：
    对应每个输入的 m，输出占一行，两个数之间以空格分隔。

样例输入:
20
1000

样例输出:
17 19
881 883 */