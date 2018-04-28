class Solution {
public:
    int titleToNumber(string s) {
        int p=1,ans=0;
        for(int i=s.length()-1;i>=0;i--) {
            ans+=(s[i]-64)*p;
            p*=26;
        }
        return ans;
    }
};