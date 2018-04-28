class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        if (n < 3) {
            return s;
        }
        int hash[128] = {0};
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ++hash[s[i]];
            ma = max(hash[s[i]], ma);
        }
        vector <vector <char> > bucket(ma + 1, vector<char> ());
        for (int i = 0; i < n; ++i) {
            bucket[hash[s[i]]].push_back(s[i]);
            hash[s[i]] = 0;
        }
        string ans = "";
        for (int i = ma; i > 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                ans += string(i, bucket[i][j]);
            }
        }
        return ans;
    }
};