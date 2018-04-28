class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return {};
        }
        stack<int> s;
        s.push(nums[0]);
        vector<int> ans(n, INT_MIN);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (ans[i] != INT_MIN) {
                continue;
            }
            ans[i] = -1;
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
        }
        return ans;
    }
};