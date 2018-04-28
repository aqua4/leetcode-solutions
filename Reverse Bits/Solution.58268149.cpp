class Solution {
public:
    bool bit(uint32_t x, int i) {
        return x & (1<<i);
    }
    
    uint32_t reverseBits(uint32_t n) {
        for (int i=0;i<16;i++)
        if (bit(n,i) != bit(n,31-i)) n^=(1<<i),n^=(1<<(31-i));
        return n;
    }
};