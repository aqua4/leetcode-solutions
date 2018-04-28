class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        //cout << x;
        int i = 0;
        int ans = 0;
        long long p = 1;
        while (p > 0 && p <= x) {
            p = (long long)(1<<i);
            if (x & p) ans++;
            i++;
        }
        return ans;
    }
};