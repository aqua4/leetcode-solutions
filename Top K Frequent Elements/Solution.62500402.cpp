class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m,num;
        vector<int> v;
        vector<int> first(n+1,0);
        for (int i=0;i<n;i++) {
            int count = m[nums[i]];
            int mapping = num[nums[i]];
            if (!count) {
                num[nums[i]] = v.size();
                v.push_back(nums[i]);
            } else {
                swap(v[first[count]],v[mapping]);
                num[v[mapping]] = mapping;
                num[nums[i]] = first[count];
                first[count]++;
            }    
            m[nums[i]]++;
        }
        return vector<int> (v.begin(),v.begin()+k);
    }
};