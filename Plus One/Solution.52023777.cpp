class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        if (!len) return digits;
        if (digits[len-1]+1<10) digits[len-1]++; 
        else {
            int i=len-1;
            while(i>=0 && digits[i]==9) {
                digits[i]=0;
                i--;
            }
            if (i==-1) digits.insert(digits.begin(),1); else digits[i]++;
        }
        return digits;
    }
};