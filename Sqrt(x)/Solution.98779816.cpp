class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long long l = 0;
        long long r = x / 2;
        long long m;
        while (l <= r) {
            m = (l + r) / 2;
            if (m * m == x) {
                return m;
            }
            if (r * r == x) {
                return r;
            }
            if (l * l == x) {
                return l;
            }
            if (m * m > x) {
                r = m - 1;
                continue;
            }
            l = m + 1;
        }
        return l * l > x ? l - 1 : l;
    }
};