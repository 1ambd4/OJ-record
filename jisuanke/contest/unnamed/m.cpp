#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
	char a[100010],b[100010];
	int n;
	scanf("%s%d", &a, &n);
	int l=strlen(a);
	for(int i=0; i<n; i++)
	{
		scanf("%s", &b);
		int k=0, cnt=0;
		for(int j=0; j<strlen(b); j++)
		{ 
			for(; k<l; k++)
			{
				if(a[k]==b[j]) 
				{
					cnt++;
					break;
				}
			}
			k++;
		}
		if(cnt==strlen(b)) printf("YES\n");
		else printf("NO\n");
	}
}