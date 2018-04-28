class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp = nums;
        vector<vector<int> > ans;
        while(1) {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
            if (temp == nums) {
                break;
            }
        }
        return ans;
    }
};