class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        priority_queue<int, vector<int>, greater<int> > heap;
        for (int i = 0; i < k; ++i) {
            heap.push(nums[i]);
        }
        for (int i = k; i < n; ++i) {
            heap.push(nums[i]);
            heap.pop();
        }
        return heap.top();
    }
};