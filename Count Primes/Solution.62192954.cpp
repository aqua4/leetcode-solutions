class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n,1);
        int ans=0;
        int i;
        for (i=2;i*i<n;i++) {
            if (!p[i]) continue;
            ans++;
            for (int j=i*i;j<n;j+=i) p[j]=0;
        }
        for (;i<n;i++) ans+=p[i];
        return ans;
    }
};