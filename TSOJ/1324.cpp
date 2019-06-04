#include <iostream>
using namespace std;

int main(void) {
	int n, temp, num, max;
	cin >> n;
	bg:
	while (n--) {
		num = 0, max = 0;
		while (cin >> temp) {
			if (temp == -1) {
				cout <<  num << endl;
				goto bg;
			}
			else {
				if (temp > max) {
					num++;
					max = temp;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}


/* 题目描述:
    Peter喜欢中国的名山大川，看着层峦叠嶂的秀美景色。Peter完全乐不思美了。望着眼前云雾缭绕的山峦，他开始怀疑自己的眼睛了。到底有多少座山峰啊？！ 能帮着他数数吗？高山峰一定会遮挡住它后面的矮山峰，即使高度相同，也只能看到前面的一座。

输入描述：
    第一行的正整数n，表示输入数据的组数。接下来的n行，每行若干个正整数，以-1表示当前行的结束

输出描述：
    每行一个结果，表示能看到的山峰个数

样例输入:
3
1 2 3 4 5 6 7 8 9 -1
7 1 2 6 8 9 10 3 -1
100 20 200 200 205 300 1000 800 -1

样例输出:
9
4
5 */