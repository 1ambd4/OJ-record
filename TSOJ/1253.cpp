#include <iostream>
#include <cstdio>
#include <malloc.h>
using namespace std;

struct stu {
	char name[20];
	short id;
	int score;
};
typedef  struct stu ss;
typedef ss *ssr;

int main(void) {
	freopen("in.txt", "r", stdin);
	int n, nb, a, b, c;
	cin >> n;
	nb = n;
	ssr ptr = (ssr)malloc(sizeof(ss) * n);
	ssr ptrb = ptr;
	while (nb--) {
		cin >> ptr->name >> ptr->id;
		for (int i = 0; i < 3; i++)		cin >> a >> b >> c;
		ptr->score = a + b + c;
		ptr++;
	}
	for (int i = 0; i < n; i++) {
		cout << ptrb++->score << " ";
	}

}