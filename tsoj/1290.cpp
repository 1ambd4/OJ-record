#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1005], v[1005];

int main(void) {
    int n, m;
   while (cin >> m >> n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= v[i]; j--) {
                dp[j] = max(dp[j], dp[j-v[i]] + v[i]);
            }
        }

        cout << m-dp[m] << endl;
   }
    return 0;
}


/* [2016 NUIST 程序设计竞赛]
G. 希尔伯特的空间
描述
希尔伯特领导的数学学派是19世纪末20世纪初数学界的一面旗帜，希尔伯特被称为“数学界的无冕之王”，他是天才中的天才。他在对积分方程的研究中研究了希尔伯特空间。希尔伯特空间是欧几里德空间的一个推广，其不再局限于有限维的情形。

希尔伯特带来了一个容量为n的空间,以及m个体积不同的物体。希望你能尽可能多占有空间，每件物品不可拆分，计算最小的剩余容量数。

输入
第一行一个整数n表示空间的容量。

第二行一个整数m表示一共有m个不同的物体。

接下来m行分别表示m个物体的体积。

输出
输出一个整数，表示空间最小的剩余容量。

样例输入
3

1

3

样例输出
0 */
