class Solution {
public:
    bool isAnagram(string s, string t) {
        int lens=s.length();
        int lent=t.length();
        if (lens!=lent) return 0;
        int ch[100001];
        for(int i=0;i<lens;i++) ch[s[i]]=0,ch[t[i]]=0;
        for(int i=0;i<lens;i++) {
            ch[s[i]]++;
            ch[t[i]]--;
            cout<<ch[s[i]]<<" "<<ch[t[i]]<<endl;
        }
        
        for(int i=0;i<lens;i++) {
            if (ch[s[i]] || ch[t[i]]) return 0;
        }
        return 1;
    }
};