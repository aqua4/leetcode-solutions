class Solution {
public:
    int reverse(int x) {
        bool neg=0;
        if (x<0) {
            neg=1;
            x=abs(x);
        }
        string s = to_string(x);
        int len = s.length();
        for (int i=0;i<=len/2-1;i++) swap(s[i],s[len-i-1]);
        //cout<<s;
        if (len>9 && s>"2147483647") return 0;
        x = stoi(s);
        return (neg) ? -x : x;
    }
};