#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		if (s[0] == 'l') cout << "xianggu" << endl;
		else cout << "lansou" << endl;
	}
	return 0;
}


/* 链接：https://www.nowcoder.com/acm/contest/28/A
来源：牛客网

题目描述 
 这是mengxiang000和Tabris来到幼儿园的第一天，mengxiang000和Tabris一见面就很投缘，mengxiang000先说一句话，Tabris就会紧接着说一句话。如果mengxiang000说的是lansou，那么Tabris就会紧接着说xianggu、相反，如果mengxiang000说的是xianggu、那么Tabris就会紧接着说lansou。
输入描述:
第一行输入一个整数t，表示一共的测试数据组数。
每组数据输入一行，包含一个字符串，表示mengxiang000所说的话。
1<=t<=10
输出描述:
每组数据输出一行，包含一个字符串，表示Tabris所说的话。
示例1
输入
2
lansou
xianggu
输出
xianggu
lansou */