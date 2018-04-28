class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> bits(len+1,0);
        for (int i=0;i<len;i++) {
            for (int j=0;j<words[i].length();j++) {
                bits[i] |= (1 << (words[i][j]-97));
            }
        }
        int ans = 0;
        for (int i=0;i<len-1;i++) {
            for (int j=i+1;j<len;j++) {
                int p = words[i].length() * words[j].length();
                if ((bits[i] & bits[j]) == 0) { if (len<20) cout << i << " "<<j<<endl; ans = max(ans,p); }
            }
        }
        return ans;
    }
};