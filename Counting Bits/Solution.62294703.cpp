class Solution {
public:
    bool bit (int x, int i) {
        return x & (1<<i);
    }
    
    vector<int> countBits(int num) {
         if (!num) return {0};
        int a[num+1]={0,1};
        int p = 1;
        int t = 0;
        for (int i=2;i<=num;i++) {
             (t<p) ? a[i] = a[i-p] : a[i] = a[i-p]+1;
             t++;
             if (t >= p*2) {
                 p<<=1;
                 t = 0;
             }
        }
        vector<int> v(a,a+num+1);
        return v;
    }
};