#include <iostream>
using namespace std;

int main(void) {
	int t, key;
	int n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int le = k+n;
		for (int i = n; i <= le; i++) {
			if (i % m != 0) key = 0;
			else {key = 1; break;} 
		}
		if (key) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}


/* #include <iostream>
using namespace std;
int main()
{
    int n,m,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cout<<(m-(n%m?n%m:m)<=k?"YES":"NO")<<endl;
    }
    return 0;
} */

/* 链接：https://www.nowcoder.com/acm/contest/28/B
来源：牛客网

题目描述 
 今天是Tabris和mengxiang000来到幼儿园的第二天，美丽的老师决定给幼儿园的乖宝宝们发苹果，但是准备分给孩子们的苹果只有N个，幼儿园一共有M 个孩子。为了不偏袒任何一个孩子，老师决定，给每个孩子的苹果数一样多，如果不够的话从自己有的K个苹果中拿出一些分给孩子们。现在老师想知道每个孩子能分得一样多的苹果么？
输入描述:
本题有T组数据
每行有三个整数N,M,K分别代表准备分给孩子们的N个苹果，一共有M个孩子，老师有K个苹果。
1≤T≤200
1≤N，M，K≤100000
输出描述:
如果能使每个孩子得到的苹果数目一样输出YES，否则输出NO。
示例1
输入
3
5 4 3
8 4 3
11 5 3
输出
YES
YES
NO */