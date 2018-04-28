class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for (int i=1;i<n;i++) {
            int c=0;
            string st="";
            int len = s.length();
            for (int j=0;j<len;) {
                int p = j;
                j++;
                while (s[j]==s[j-1] && j<len) j++;
                st=st+to_string(j-p)+s[p];
            }
            s = st;
        }
        return s;
    }
};