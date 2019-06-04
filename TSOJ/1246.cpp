#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	int side[3];
	while (cin >> side[0] >> side[1] >> side[2]) {
		double area = 0, p = 0;
		sort(side, side+3);
		if (side[0] + side[1] > side[2]) {
			p = (side[0] + side[1] + side[2]) / 2.0;
			area = sqrt(p * (p - side[0]) * (p - side[1]) * (p - side[2]));
			printf("%.4f\n", area);
		}
		else {
			cout << "0" << endl;
		}
	}
	return 0;
}


/* 题目描述:
    三个整数可能构成三角形的三条边，当然也可能不能构成三条边。如果能构成三角形，可以利用海伦公式计算三角形的面积。

输入描述：
    多组输入，占一行，输入用空格分开的三个整数，分别表示三角形的三条边。

输出描述：
    占一行，当输入的三个数能构成三角形时，求三角形的面积，并保留 4 位小数。否则输出整数 0。

样例输入:
3 4 5
1 2 1

样例输出:
6.0000
0 */