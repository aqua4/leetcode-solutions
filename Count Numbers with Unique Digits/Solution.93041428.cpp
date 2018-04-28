class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) {
            n = 10;
        }
        vector<int> prec = {1, 9};
        for (int i = 9; i > 0; --i) {
            prec.push_back(prec.back() * i);
        }
        vector<int> nums(1, 1);
        for (int i = 1; i <= n; ++i) {
            nums.push_back(nums[i - 1] + prec[i]);
        }
        return nums[n];
    }
};