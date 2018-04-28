class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        if (n < 3) {
            return s;
        }
        int hash[128] = {0};
        vector<pair<int, char> > p;
        for (int i = 0; i < n; ++i) {
            --hash[s[i]];
        }
        for (int i = 0; i < n; ++i) {
            p.push_back(make_pair(hash[s[i]], s[i]));
        }
        sort(p.begin(), p.end());
        string ans = "";
        for (int i = 0; i < n; ++i) {
            ans += p[i].second;
        }
        return ans;
    }
};