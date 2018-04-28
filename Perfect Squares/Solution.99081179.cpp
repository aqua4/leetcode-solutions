class Solution {
public:
    int numSquares(int n) {
        int sq = sqrt(n);
        if (n == sq * sq) {
            return 1;
        }
        for (int i = 1; i * i < n; ++i) {
            int sq = (int)sqrt(n - i * i);
            if (i * i + sq * sq == n) {
                return 2;
            }
        }
        for (int i = 1; i * i < n - 1; ++i) {
            for (int j = i; i * i + j * j < n; ++j) {
                int sq = (int)(sqrt(n - i * i - j * j));
                if (i * i + j * j + sq * sq == n) {
                    return 3;
                }
            }
        }
        return 4;
    }
};