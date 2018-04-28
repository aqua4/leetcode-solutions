class Solution {
public:
    bool isUgly(int num) {
        if (num<1) return 0;
        if (num<7) return 1;
        while(num>6) {
            int b=0;
            if (num%5==0) num/=5,b=1;
            if (num%3==0) num/=3,b=1;
            if (num%2==0) num/=2,b=1;
            if (!b && num>6) return 0;
        }
        return 1;
    }
};