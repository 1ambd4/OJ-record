#include <iostream>
#include <cstdio>
// #include <malloc.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void) {
#ifdef LOCAL
	freopen("1002.in", "r", stdin);
#endif
	int T;
	char ch;
	bool flag = false;
	scanf("%d", &T);
	int *num = (int*)malloc(sizeof(int) * T + 10);
	getchar();
	for (int i = 0; i < T; ++i) {
		int tmp = 0;
		for (int j = 0; j < 7; ++j) {
			ch = getchar();
			while (!isalnum(ch)) ch = getchar();
			if (isdigit(ch)) tmp = tmp * 10 + ch - '0';
			else if (isalpha(ch)) {
				if (ch >= 'A' && ch <= 'P') {
					tmp = tmp * 10 + (ch - 'A') / 3 + 2;
				}
				else if (ch >= 'R' && ch <= 'Y') {
					tmp = tmp * 10 + (ch - 'A' - 1) / 3 + 2;
				}
			}
		}
		// cout << tmp << endl;
		num[i] = tmp;
	}

	sort(num, num + T); num[T] = 0;
	// for (int i = 0; i < T; ++i) cout << num[i] << " "; cout << endl;
	for (int i = 0; i < T; ++i) {
		int cnt = 1;
		while (num[i] == num[i+1]) {
			cnt++;
			i++;
		}
		if (cnt > 1) {
			flag = true;
			// cout << num[i] << " " << cnt << endl;
			printf("%03d-%04d %d\n", num[i] / 10000, num[i] % 10000, cnt);
		}
	}
	if (!flag) {
		printf("No duplicates.\n");
	}

	return 0;
}