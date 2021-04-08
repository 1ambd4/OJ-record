#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	int n;
	string str;
	cin >> n;
	char tmp;
	cin.get(tmp);
	while (n--) {
		str.clear();
		getline(cin, str);
		//cout << str.length() << endl;
		int len = str.length();

		for (int i = len-1; i >= 0; i--) {
			cout << str[i];
		}

		cout << endl;
	}

	return 0;
}


/* 题目描述:
Sine的一个朋友疯了，最近他老爱说反话，别人说什么他就倒着说一遍，真是个奇怪的人。那他到底说了什么呢？
（他说的话不超过1000个字符。）

输入描述：
输入一个正整数n，表示说话的次数。下面n行表示说的话

输出描述：
占n行，每行表示对应输入的反话

样例输入:
2
i am speaking
ACMer

样例输出:
gnikaeps ma i
reMCA */