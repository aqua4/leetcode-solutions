class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string> > ans;
        vector<vector<int> > hash(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < strs[i].length(); ++j) {
                ++hash[i][strs[i][j] - 'a'];
            }
        }
        bool used[n] = {0};
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            ans.push_back(vector<string>());
            ans[ans.size() - 1].push_back(strs[i]);
            for (int j = i + 1; j < n; ++j) {
                if (used[j] || strs[i].length() != strs[j].length()) {
                    continue;
                }
                bool same = 1;
                for (int k = 0; k < 26; ++k) {
                    if (hash[i][k] != hash[j][k]) {
                        same = 0;
                        break;
                    }
                }
                if (same) {
                    used[j] = 1;
                    ans[ans.size() - 1].push_back(strs[j]);
                }
            }
        }
        return ans;
    }
};