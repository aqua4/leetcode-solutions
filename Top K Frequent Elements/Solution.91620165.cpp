class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ++hash[nums[i]];
            ma = max(hash[nums[i]], ma);
        }
        vector< vector<int> > bucket(ma + 1, vector<int>());
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            bucket[it->second].push_back(it->first);
        }
        vector<int> ans;
        for (int i = ma; i > 0; --i) {
            if (bucket[i].size()) {
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
                k -= bucket[i].size();
            }
            if (!k) break;
        }
        return ans;
    }
};