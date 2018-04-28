class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length();
        int ans=0,last=0;
        for (int i=0;i<len;i++) {
            if (s[i]==' ') {if (ans) last=ans; ans=0;} else ans++;
        }
        return !ans ? last : ans;
    }
};