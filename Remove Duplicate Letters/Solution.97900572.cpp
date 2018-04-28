class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        if (!n) {
            return s;
        }
        vector<int> hash(26, -1);
        for (int i = n - 1; i >= 0; --i) {
            if (hash[s[i] - 'a'] == -1) {
                hash[s[i] - 'a'] = i;
            }
        }
        string ans = "";
        stack<int> last;
        int used = 0;
        for (int i = 0; i < n; ++i) {
            int index = s[i] - 'a';
            if (used & (1<<index)) {
                continue;
            }
            //cout << s[i] << " " << ans << endl;
            while (!last.empty() && ans.back() > s[i] && last.top() > i) {
                last.pop();
                used ^= (1 << (ans.back() - 'a'));
                ans.pop_back();
            }
            used |= (1<<index);
            last.push(hash[index]);
            ans += s[i];
        }
        return ans;
    }
};