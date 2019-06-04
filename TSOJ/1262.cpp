//提交代码的时候把重定向语句注释掉!!!

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 200;
int main(void) {
	//freopen("in.txt", "r", stdin);
	//freopen("out.text", "w", stdout);
	int n, len, flag;
	char arr[maxn], brr[maxn];
	while(cin >> n) {
		while (n--) {
			memset(arr, 0, sizeof(arr));
			memset(arr, 0, sizeof(brr));
			cin >> arr;
			flag = 0;
			len = strlen(arr);
			for (int i = 2; i < len; i++) {
				brr[i-2] = arr[i];
			}
			brr[len-1] = arr[0];
			brr[len-2] = arr[1];
/* 			for (int i = 0; i < len; i++) cout << arr[i];
			cout << endl;
			for (int i = 0; i < len; i++) cout << brr[i];
			cout << endl; */
			//cout << strcmp(arr, brr) << endl;
/* 			if (strcmp(arr, brr) != 0) {
				for (int i = 0; i < len; i++) {
					cout << brr[i];
				}
				cout << endl;
			}
			else {
				cout << "NO" << endl;
			} */
			//cout << strlen(arr) << " " << strlen(brr) << " "<< strcmp(arr, brr) << endl;
			for (int i = 0; i < len; i++)
				if (arr[i] != brr[i]) flag = 1;
			if (flag) {
				for (int i = 0; i < len; i++) cout << brr[i];
				cout << endl;
			}
			else {
				cout << "NO" << endl;
			}
			//cout << flag << endl;
		}
	}
	return 0;
}



/* 题目描述:
现在给出一种新的方法产生单词。对于给定一个单词（长度大于 3），从第 3 位开始将其后的字母作为单词的首部，前两位逆序后接在首部之后，构成新的单词。若得到的单词与原单词一致，则输出 NO，否则输出这个新单词。

输入描述：
第一行表示有 n 个单词，接着的 n 行每行表示一个单词

输出描述：
每行一个单词，若不能构成新单词，则输出 NO

样例输入:
3
throw
especially
level

样例输出:
rowht
peciallyse
velel */