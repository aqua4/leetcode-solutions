class Solution {
public:
    bool isUgly(int num) {
        if (num<1) return 0;
        if (num<7) return 1;
        while (num%5==0) num/=5;
        while (num%3==0) num/=3;
        while (num%2==0) num/=2;
        return num==1;
    }
};