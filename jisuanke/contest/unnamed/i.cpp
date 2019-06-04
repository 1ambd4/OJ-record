#include <stdio.h>
#include <iostream>
using namespace std;
int a[500005 * 2];
int main()
{
#ifdef LOCAL
    freopen("i.in", "r", stdin);
#endif
	long long n,sum=0,max=-9999999999;
	scanf("%lld", &n);
    if (n == 1) { int t; cin >> t; cout << t << endl; return 0; }
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++)
	{
		sum=a[i]; max = sum > max ? sum : max;
		for(int j=i+1; j<n; j++)
		{
			if(a[j]>=a[i]) sum+=a[j];
			else break;
			if(a[i]*sum>max) max=a[i]*sum;
		}
		for(int j=i-1; j>=0; j--)
		{
			if(a[j]>=a[i]) sum+=a[j];
			else break;
			if(a[i]*sum>max) max=a[i]*sum;
		}
		
	}
	
	printf("%lld\n", max);
}