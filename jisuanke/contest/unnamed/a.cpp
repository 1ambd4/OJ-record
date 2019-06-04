#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


int main(void) {
    for (long long i = 5; i < 100000000; ++i) {
        long long _sum = 0;
        long long _t = sqrt(i+0.5);
        for (int j = 2; j  <= _t; ++j) {
            if (i % j == 0) {
                _sum += j;
                _sum += i/j;
            }
           // cout << i << "---------" << j << endl;
        }
        _sum += 1;
        if (_sum == i) cout << _sum << endl;
        //cout << _sum << endl;
    }
    return 0;
}

#include <iostream>
#include <cmath> 
#include<cstring>
using namespace std;

int cnt,s[10000000],j,t,k;

void fun1(int n)
{
	memset(s, 0,10000000);
	j = 1;
	t = n;
	s[0] = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (t % i == 0)
		{
			s[j++] = i;
			s[j++] = t / i;
		}
	}
}

int main()
{
	int sum=0;
	for (int i = 3; ; i++)
	{
		fun1(i);
		sum = 0;
		for (k = 0; k < j; k++)
		{
			sum += s[k];
			
		}
		if (sum == i)
		{
			cnt++;
			cout << i << " ";
			if (cnt >= 5)
				break;
		}
		/*if (cnt >= 5)
			break;*/
	}
	return 0;
}