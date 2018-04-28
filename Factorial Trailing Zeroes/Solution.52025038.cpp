class Solution {
public:
    int trailingZeroes(int n) {
        long long p=5;
        int ans=0;
        while (p<=(long long)n) {
            ans+=n/(int)p;
            p*=5;
        }
        return ans;
    }
};