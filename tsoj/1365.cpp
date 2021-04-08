#include <iostream>
#include <cstdlib>
using namespace std;

int maxsum(int *a, int x, int y) {
    int v, L, R, maxs;
    if (y - x == 1) return a[x];
    int m = x + (y - x) / 2;
    maxs = max(maxsum(a, x, m), maxsum(a, m, y));
    v = 0; L = a[m-1];
    for (int i = m-1; i >= x; i--)
        L = max(L, v += a[i]);
    v = 0; R = a[m];
    for (int i = m; i < y; i++)         
        R = max(R, v += a[i]);
    return max(maxs, L+R); 
}

int main(void) {
	int n;
	while(cin >> n) {
		int *p = (int *)malloc(sizeof(int));
		int i = 0, temp, bk = n;
		while (n--) {
			cin >> temp;
			p[i++] = temp;
		}
		cout << maxsum(p, 0, bk) << endl;
	}
	return 0;
}