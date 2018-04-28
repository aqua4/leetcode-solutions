class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) {
            return 0;
        }
        while (s.back() == ' ') s.pop_back();
        if (s.length() == 0) {
            return 0;
        }
        int l = 0;
        while (!s.empty() && s.back() != ' ') {
            ++l;
            s.pop_back();
        }
        return l;
    }
};