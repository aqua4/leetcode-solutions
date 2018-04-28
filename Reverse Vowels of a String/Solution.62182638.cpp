class Solution {
public:
    string reverseVowels(string s) {
        int p1 = 0;
        int len = s.length();
        int p2 = len-1;
        char vowels[]={'a','e','i','u','A','E','I','O','U','o'};
        while (p1<p2) {
            while (find(vowels,vowels+12,s[p1])==vowels+12) p1++;
            while (find(vowels,vowels+12,s[p2])==vowels+12) p2--;
            if (p1<p2) swap(s[p1],s[p2]);
            p1++;
            p2--;
        }
        return s;
    }
};