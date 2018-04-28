class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        vector<char> st2;
        int cur = 0;
        for (; cur < s.length(); ++cur) {
            string num = "";
            while (cur < s.length() && s[cur] == ' ') {
                ++cur;
            }
            while (cur < s.length() && isdigit(s[cur])) {
                num += s[cur];
                ++cur;
            }
            if (num.empty()) {
                continue;
            }
            int a = stoi(num);
            if (!st2.empty() && st2.back() == '*') {
                st.back() *= a;
                st2.pop_back();
            } 
            else if (!st2.empty() && st2.back() == '/') {
                st.back() /= a;
                st2.pop_back();
            }
            else {
                st.push_back(a);
            }
            while (cur < s.length() && s[cur] == ' ') {
                ++cur;
            }
            if (cur >= s.length()) {
                continue;
            }
            if (s[cur] == '+' || s[cur] == '-' || s[cur] == '*' || s[cur] == '/') {
                st2.push_back(s[cur]);
            }
        }
        int ans = st[0];
        for (int i = 1; i < st.size(); ++i) {
            if (st2[i - 1] == '+') {
                ans += st[i];
                continue;
            }
            ans -= st[i];
        }
        return ans;
    }
};