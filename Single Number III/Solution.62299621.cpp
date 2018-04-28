class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int i=0;i<nums.size();i++) {
            if (!s.count(nums[i])) s.insert(nums[i]); else s.erase(nums[i]);
        }
        return {s.begin(),s.end()};
    }
};