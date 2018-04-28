class Solution {
public:
    void palindrom(string s, vector<string>& vs, vector<vector<string> >& ans) {
        int n = s.length();
        if (n == 1) {
            vs.push_back(s);
            ans.push_back(vs);
            vs.pop_back();
            return;
        }
        vs.push_back(s.substr(0, 1));
        palindrom(s.substr(1), vs, ans);
        vs.pop_back();
        for (int i = 1; i < n; ++i) {
            bool no = 0;
            for (int j = 0; j < (i + 1) / 2; ++j) {
                if (s[j] != s[i - j]) {
                    no = 1;
                    break;
                }
            }
            if (!no) {
                vs.push_back(s.substr(0, i + 1));
                if (i == n - 1) {
                    ans.push_back(vs);
                }
                else {
                    palindrom(s.substr(i + 1), vs, ans);
                }
                vs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> vs;
        vector<vector<string> > ans;
        palindrom(s, vs, ans);
        return ans;
    }
};