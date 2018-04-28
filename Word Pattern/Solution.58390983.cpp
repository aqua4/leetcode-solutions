class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int p=0;
        string s[27];
        map<string,char> m;
        for (int i=0;i<pattern.length();i++) {
            cout<<i<<" ";
            if (p>=str.length()) return 0;
            if (s[pattern[i]-97]=="") {
                while (p<str.length() && str[p]!=' ') {
                    s[pattern[i]-97]+=str[p];
                    p++;
                }
                if (m[s[pattern[i]-97]]) return 0;
                m[s[pattern[i]-97]]=pattern[i];
                p++;
            } else {
                cout<<"done ";
                int len=p;
                while (p<str.length() && str[p]!=' ') {
                    if (p-len>s[pattern[i]-97].length()-1 || s[pattern[i]-97][p-len]!=str[p]) return 0;
                    p++;
                }
                p++;
            }    
        }
        cout<<p;
        return p>=str.length();
    }
};