#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> flood_fill(vector<vector<int>>& image, int sr, int sc, int nc)
{
    const int dx[] { 1, 0, 0, -1 };
    const int dy[] { 0, 1, -1, 0 };
    int cc = image[sr][sc];
    if (cc == nc) return image;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = nc;
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == cc) {
                q.push({nx, ny});
                image[nx][ny] = nc;
            }
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> image(3);
    image[0] = { 1, 1, 1 };
    image[1] = { 1, 1, 0 };
    image[2] = { 1, 0, 1 };
    vector<vector<int>> ans = flood_fill(image, 1, 1, 2);
    for_each(ans.begin(), ans.end(), [](vector<int>& nums) {
                for (const int& num : nums) { cout << num << " "; }
                cout << endl;
            });
    return 0;
}
