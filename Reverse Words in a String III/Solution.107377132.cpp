class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string word = "";
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                reverse(word.begin(), word.end());
                ans += word + " ";
                word = "";
                continue;
            }
            word += s[i];
        }
        reverse(word.begin(), word.end());
        return ans + word;
    }
};