#include <cstdio>
#include <iostream>
using namespace std;

short solve(short n) {
	short cnt[7]={0},datenum[12]={31,0,31,30,31,30,31,31,30,31,30,31},head=1;
	for(short i=2016;i<=n;i++) {
		for(short j=1;j<=12;j++) {
				cnt[(head+11)%7]++;
				head=j==2?i%100==0?i%400==0?(head+29)%7:(head+28)%7:i%4==0?(head+29)%7:(head+28)%7:(head+datenum[j-1])%7;
		}
	}
	return cnt[5] - 2;
	
}

short dg(short n) {
	if (n == 2016) {
		return solve(n);
	}
	else {
		return solve(n) - solve(n-1);
	}
}
int main(void) {
	//freopen("in.txt", "r", stdin);
	short n;
	while (cin >> n) {
		cout << n << " " << dg(n) << endl;
	}
	return 0;
}



/* 题目描述：
    有些西方人比较迷信，如果某个月的13号正好是星期五，他们就会觉得不太吉利，用古人的说法，就是“诸事不宜”。请你编写一个程序，统计出在某个特定的年份中，出现了多少次既是13号又是星期五的情形，以帮助你的迷信朋友解决难题。

    说明：
    （1）一年有365天，闰年有366天，所谓闰年，即能被4整除且不能被100整除的年份，或是既能被100整除也能被400整除的年份；
    （2）已知2016年1月1日是星期五，用户输入的年份肯定大于或等于2016年。

输入：
    每行一个某个特定的年份N（N大于或等于2016年）

输出：
    每行包含两个正整数，用一个空格隔开，即在这一年中，出现了多少次既是13号又是星期五的情形

样例输入：
2016
2017

样例输出：
2016 1
2017 2 */