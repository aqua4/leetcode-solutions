/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
int gcd(int a, int b) {
    while (a && b) {
        (a > b) ? a %= b : b %= a;
    }
    return a + b;
}
    int maxPoints(vector<Point>& points) {
    int n = points.size();
    if (!n) {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        map<pair<int, int>, int> hash;
        int cur = 1;
        int xx = 0;
        for (int j = i + 1; j < n; ++j) {
            if(points[i].x == points[j].x) {
                if (points[i].y == points[j].y) {
                    ++cur;
                    continue;
                }
                ++xx;
                continue;
            }
            int y = points[i].y - points[j].y;
            int x = points[i].x - points[j].x;
            if (x < 0) {
                x = -x;
                y = -y;
            }
            int nod = gcd(abs(x), abs(y));
            ++hash[make_pair(x / nod, y / nod)];
        }
        ans = max(ans, cur + xx);
        for (const auto &j : hash) {
            ans = max(ans, j.second + cur);
        }
    }
    return ans;
    }
};