class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        int len=secret.length();
        vector<vector<int> > v(12,vector<int>(0));
        for (int i=0;i<len;i++) {
            if (secret[i]==guess[i]) {
                bulls++;
                secret[i]=':';
                guess[i]=':';
            } else {
                v[secret[i]-48].push_back(secret[i]);
            }
        }
        for (int i=0;i<len;i++) {
            if (!v[guess[i]-48].empty()) {
                    v[guess[i]-48].pop_back();
                    cows++;
                }
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};