class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int len = s.length();
        int p1 = 0;
        int p2 = len-1;
        while (p1<p2) {
            while ((!isdigit(s[p1]) && (s[p1]<'a' || s[p1]>'z')) && p1<p2) p1++;
            while (((s[p2]<'a' || s[p2]>'z') && !isdigit(s[p2])) && p1<p2) p2--;
            if (p1<p2 && s[p1]!=s[p2]) return 0;
            p1++;
            p2--;
        }    
        return 1;
    }
};