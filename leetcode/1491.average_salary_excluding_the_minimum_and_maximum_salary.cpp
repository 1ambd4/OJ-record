#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double average(vector<int>& salary)
{
    int minimum = salary[0], maximum = salary[0];
    int n = salary.size();
    double res = 0;

    for (int i = 0; i < n; ++i) {
        minimum = min(minimum, salary[i]);
        maximum = max(maximum, salary[i]);
        res += salary[i];
    }

    res = res - minimum - maximum;

    return res / (n-2);
}

int main()
{
    vector<int> salary1 { 1000, 2000, 3000 };
    cout << average(salary1) << endl;

    vector<int> salary2 { 6000, 5000, 4000, 3000, 2000, 1000 };
    cout << average(salary2) << endl;

    vector<int> salary3 { 8000, 9000, 2000, 3000, 6000, 1000 };
    cout << average(salary3) << endl;

    return 0;
}

