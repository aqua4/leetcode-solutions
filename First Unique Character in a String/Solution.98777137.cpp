class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> hash(26, 0);
        for (int i = 0; i < n; ++i) {
            if (!hash[s[i] - 'a']) {
                hash[s[i] - 'a'] = i + 1;
                continue;
            }
            hash[s[i] - 'a'] = -1;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (hash[i] > 0) {
                ans = min(ans, hash[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans - 1;
    }
};