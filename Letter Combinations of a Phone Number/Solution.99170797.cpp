class Solution {
public:
    void dfs(int cur, string s, string& digits, vector<string>& h, vector<string>& ans) {
        if (cur == digits.size()) {
            ans.push_back(s);
            return;
        }
        for (int i = 0; i < h[digits[cur] - '0'].length(); ++i) {
            dfs(cur + 1, s + h[digits[cur] - '0'][i], digits, h, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (!n) {
            return {};
        }
        vector<string> h = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        dfs(0, "", digits, h, ans);
        return ans;
    }
};