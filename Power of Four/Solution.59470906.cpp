class Solution {
public:
    bool bit(int x,int i) {
        return x & (1<<i);
    }
    
    bool isPowerOfFour(int num) {
        bool b=0;
        if (!num) return 0;
        for(int i=0;i<32;i++)
        if (bit(num,i))
        if (i%2==1 || b) return 0; else b=1;
        return 1;
    }
};