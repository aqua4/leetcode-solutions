class Solution {
public:
    string reverseString(string s) {
        reverse(begin(s),end(s));
        return s;
    }
};