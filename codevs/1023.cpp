#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int n;
    float a, b, sum = 0, t = 0;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        sum += a * b;
        t += a;
    }
    printf("%.2f\n", sum/t);
    return 0;
}