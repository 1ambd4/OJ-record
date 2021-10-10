#include <iostream>
#include <cmath>

using namespace std;

int arrange_conins(int n)
{
    return (sqrt((long)8*n+1) - 1) / 2;
}

int main()
{
    cout << arrange_conins(1) << endl;
    cout << arrange_conins(3) << endl;
    cout << arrange_conins(5) << endl;
    cout << arrange_conins(8) << endl;
    return 0;
}
