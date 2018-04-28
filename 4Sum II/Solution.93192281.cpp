class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if (!n) {
            return 0;
        }
        vector<int> sums1;
        vector<int> sums2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sums1.push_back(A[i] + B[j]);
                sums2.push_back(C[i] + D[j]);
            }
        }
        unordered_map<int, int> hash;
        for (int i = 0; i < n * n; ++i) {
            ++hash[sums1[i]];
        }
        int ans = 0;
        for (int i = 0; i < n * n; ++i) {
            int h = hash[-sums2[i]];
            if (h) {
                ans += h;
            }
        }
        return ans;
    }
};