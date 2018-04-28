class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if (!J.length() || !S.length()) {
            return 0;
        }
        bool a[128] = {0};
        int ans = 0;
        for (int i = 0; i < J.length(); ++i) {
            a[J[i]] = 1;
        }
        for (int i = 0; i < S.length(); ++i) {
            if (a[S[i]]) {
                ++ans;
            }
        }
        return ans;
    }
};