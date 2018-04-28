class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> bits(len+1,0);
        int ans = 0;
        for (int i=0;i<len;i++) {
            for (int j=0;j<words[i].length();j++) {
                bits[i] |= (1 << (words[i][j]-97));
            }
            for (int j=0;j<i;j++) {
                int p = words[i].length() * words[j].length();
                if ((bits[i] & bits[j]) == 0) ans = max(ans,p);
            }
        }
        return ans;
    }
};