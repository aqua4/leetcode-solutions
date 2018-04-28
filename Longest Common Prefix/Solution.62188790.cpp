class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if (!n) return "";
        for (int i=0;i<strs[0].length();i++) {
            //cout<<i;
            for (int j=1;j<n;j++) {
                if (i>=strs[j].length() || strs[j][i]!=strs[0][i]) return strs[0].substr(0,i);
            }
        }
        //cout<<"asd";
        return strs[0];
    }
};