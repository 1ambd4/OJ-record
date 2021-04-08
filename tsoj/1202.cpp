#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 20;

int main(void) {
	char str[maxn], substr[3];
	int p;
	memset(str, 0, sizeof(str));
	memset(substr, 0, sizeof(substr));
	while (cin >> str >> substr) {
		p = 0;
		int len = strlen(str);
		char a = '@';
		//cout << len << endl;
		for (int i = 1; i < len; i++) {
			if (str[i] > a) {
				p = i;
				a = str[i];
				//cout << p << endl;
			}
		}
		cout << p << endl;
		memset(str, 0, sizeof(str));
		memset(substr, 0, sizeof(substr));
	}
	return 0;
}