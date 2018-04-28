class Solution {
public:
    int findComplement(int num) {
        long long p = 1;
        while (p <= num) p*=2;
        p--;
        return num^p;
    }
};