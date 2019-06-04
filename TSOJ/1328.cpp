#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int finsh = -1;
bool cmp(const int a, const int b) {
	return a > b;
}

int main(void) {
	int n;
	int a, b, c;
	int temp;
	vector<int> v;
	cin >> n;
	while (n--) {
		int ans = 0;
		v.clear();
		cin >> a >> b >> c;
		ans = a + b + c;
		while (cin >> temp && temp != -1) {
			v.push_back(temp);
		}
		sort(v.begin(), v.end(), cmp);
/* 		for (it : v) cout << it << " ";
		cout << endl; */
		ans = ans + v.front() + v.at(1) + v[2];
		cout << ans << endl;
	}
}



/* 题目描述：
    高考计分模式今年的试点在上海、浙江开始。总体方案是3+3模式。
    除了语数外三门课程的成绩外，在学业水平测试中选择3门成绩最好的科目计入总分。

输入：
    第一行为数据的组数n，接着的n行中有若干个正整数(不超过20)，前三个分别表示语数外的成绩。每行以-1结尾

输出：
    每行一个正整数，表示高考总成绩

样例输入：
3
110 168 110 89 78 91 79 92 79 -1
100 159 108 71 79 96 91 90 67 78 -1
108 168 111 78 90 89 100 87 69 92 98 -1

样例输出：
660
644
677 */