class Solution {
public:
    string addBinary(string a, string b) {
        while (b.length()<a.length()) b='0'+b;
        while (b.length()>a.length()) a='0'+a;
        int len = a.length();
        bool leading = 0;
        for (int i=len-1;i>=0;i--) {
            a[i]=b[i]+a[i]-48;
            if (a[i]>'1') {
                if (i) a[i-1]+=1; else leading = 1;
                a[i]-=2;
            }
        }
        if (leading) return "1"+a; else return a;
    }
};