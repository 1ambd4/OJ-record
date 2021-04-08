#include <iostream>
#include <string.h>
using namespace std;

string str;
int main(void) {
	int n;
	cin >> n;
	while (n--) {
		str.clear();
		cin >> str;
		
		int len = str.length();
		int lenl = (str.length() + 1) / 2;
		int flag = 1;
		for (int i = 0; i < lenl; i++) {
			//cout << str[i] << " " << str[len - i -1] << endl;
			if (str[i] != str[len - i - 1]) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}



/* 题目描述:
一个字符串（可能包含空格）从前往后读或从后向前读都是一样的称为回文字符串（如LEVEL），输入多个字符串，判断是否是回文字符串。

输入描述：
第一行：输入一个正整数n，表示字符串个数；
接着下面输入n个字符串

输出描述：
一行，如果字符串是回文字符串，输出”Yes”，否则输出”No”

样例输入:
2
LEVEL
NUIST

样例输出:
Yes
No */