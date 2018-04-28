class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        unordered_map<int, int> arr;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                arr[nums[s.top()]] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> ans;
        for (const int &n : findNums) {
            if (arr[n]) {
                ans.push_back(arr[n]);
                continue;
            }
            ans.push_back(-1);
        }
        return ans;
    }
};