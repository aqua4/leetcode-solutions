class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while (n) {
            n--;
            ans=char(n%26+65)+ans;
            n=n/26;
        }
        return ans;
    }
};