class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int count = 0;
        int cur = A[1] - A[0];
        int cur_count = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] - A[i - 1] == cur) {
                ++cur_count;
            }
            else {
                count += (cur_count - 1) * (cur_count - 2) / 2;
                cur_count = 2;
                cur = A[i] - A[i - 1];
            }
        }
        count += (cur_count - 1) * (cur_count - 2) / 2;
        return count;
    }
};