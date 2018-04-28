class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (!n || n < k) {
            return 0;
        }
        if (k < 2) {
            return n;
        }
        //vector<vector<int> > hash(26, vector<int>());
        int hash[26] = {0};
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ++hash[s[i] - 'a'];
            ma = max(ma, hash[s[i] - 'a']);
        }
        if (ma < k) {
            return 0;
        }
        vector<int> bads;
        for (int i = 0; i < n; ++i) {
            if (hash[s[i] - 'a'] && hash[s[i] - 'a'] < k) {
                bads.push_back(i);
            }
        }
        if (!bads.size()) {
            return n;
        }
        bads.push_back(n);
        int ans = 0;
        int prev = 0;
        for (int i = 0; i < bads.size(); ++i) {
            if (bads[i] - prev >= k) {
                ans = max(ans, longestSubstring(s.substr(prev, bads[i] - prev), k));
            }
            prev = bads[i] + 1;
        }
        return ans;
    }
};