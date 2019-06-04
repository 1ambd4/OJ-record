#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}
}p[2];

double get_distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(void) {
#ifdef LOCAL
    freopen("2001.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y) {
        printf("%.2f\n", get_distance(p[0], p[1]));
    }
    return 0;
}
