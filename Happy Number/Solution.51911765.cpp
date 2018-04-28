class Solution {
public:
    bool isHappy(int n) {
        vector<bool> a(999,0);
        int x=0;
        while (1) {
            if (n==1 || n==10 || n==100) return 1;
            x=0;
            while(n) {
                x+=(n%10)*(n%10);
                n/=10;
            }
            cout<<x<<" ";
            if (a[x]) return 0;
            a[x]=1;
            n=x;
        }
    }
};