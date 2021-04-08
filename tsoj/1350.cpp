#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int * a, z, n, i;
	while(~scanf("%d%d", &z, &n)) {
		int sum = 0;
		a = (int *)malloc(sizeof(int) * z);
		for (i=0; i<z; i++) {
			a[i] = 0;
		}
		
		while (n--) {
			int c, d;
			scanf("%d%d", &c, &d);
			for(i=c-1; i<d; i++) {
				a[i]++;
			}
		}
		
		int e, f;
		scanf("%d%d", &e, &f);
		for(i=e-1; i<f; i++) {
			sum += a[i];
		}
		
		printf("%d\n", sum);
		free(a);
	}	
	return 0;
}



/* 题目描述：
    选择那些大晴天的日子,行走在孤单的海岸线,静静地种花给自己看~
    我们假设把海岸线分为n块,每块的分别标记为1...n,每块都可以种花,每次种花可以选择某个[left,right]的闭区间,每块种上一朵花.经过m次种花操作后,根据输入的区间,求该区间内花的总数.

输入描述：
    多组输入
    对每组输入，第一行有两个整数n m,分别代表总块数和种花的次数.(1 <= n, m <= 100)
    接下来的m行, 每行两个整数 L,R 代表[L,R]区间内每块种上一朵花.(1 <= L <= R <= n)
    最后一行,输入两个整数 a,b 代表最后要查询的花的总数的区间.(1 <= a <= b <= n)

输出描述
    对每组测试数据，输出区间[a,b]内花的总数

样例输入：
5 2
1 5
1 2
2 3

样例输出：
3 */