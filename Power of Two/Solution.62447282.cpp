class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<1) return 0;
        int p=1;
        for(int i=1;i<32;i++) p*=2;
        return p%n==0;
    }
};