class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.length();
        int us[129],ut[129];
        memset(us,0,sizeof(us));
        memset(ut,0,sizeof(ut));
        for (int i=1;i<=len;i++) {
            int x,y;
            if (!us[s[i-1]]) us[s[i-1]]=i,x=i; else x=us[s[i-1]];
            if (!ut[t[i-1]]) ut[t[i-1]]=i,y=i; else y=ut[t[i-1]];
            //cout<<us[s[i]-'0']<<" "<<ut[t[i]-'0']<<endl;
            if (x!=y) return 0;
        }
        return 1;
    }
};