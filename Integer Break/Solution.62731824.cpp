class Solution {
public:
    int binpow(int a, int n) {
        if (n == 0) return 1;
        if (n%2 == 1) return binpow(a, n-1)*a;
        else {
            int b = binpow(a,n/2);
            return b*b;
        }
    }
    
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n%3 == 1) return binpow(3, (n-4)/3)*4;
        if (n%3 == 2) return binpow(3, (n-2)/3)*2;
        return binpow(3, n/3);
    }
};