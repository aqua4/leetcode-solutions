class Solution {
public:
    void rec(int& n, int opened, int closed, string s, vector<string>& ans) {
        if (opened < n) {
            rec(n, opened + 1, closed, s + "(", ans);
        }
        if (closed < opened) {
            rec(n, opened, closed + 1, s + ")", ans);
        }
        if (opened == n && closed == opened) {
            ans.push_back(s);
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        vector<string> ans;
        rec(n, 0, 0, "", ans);
        return ans;
    }
};