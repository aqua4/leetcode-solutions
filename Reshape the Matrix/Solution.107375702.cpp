class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        if (!n) {
            return {{}};
        }
        int m = nums[0].size();
        if (n * m < r * c) {
            return nums;
        }
        int x = 0;
        int y = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < r; ++i) {
            ans.push_back(vector<int>());
            for (int j = 0; j < c; ++j) {
                ans[i].push_back(nums[x][y]);
                ++y;
                if (y == m) {
                    y = 0;
                    ++x;
                }
            }
        }
        return ans;
    }
};