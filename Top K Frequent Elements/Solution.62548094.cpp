class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;    // frequency of numbers
        unordered_map<int,int> num;  // indexes of numbers in the result vector
        vector<int> v;              // unique result vector
        vector<int> first(n+1,0);   // position of first number in the result vector among numbers with same frequencies
        for (int i=0;i<n;i++) {
            int count = m[nums[i]];       // frequency of current number
            int mapping = num[nums[i]];   // position of current number in the result vector
            if (!count) {               
                num[nums[i]] = v.size();    // add number to the vector if first occurence
                v.push_back(nums[i]);       
            } else {
                swap(v[first[count]],v[mapping]); // swap first number with the same frequency and current number in the result vector
                num[v[mapping]] = mapping;      
                num[nums[i]] = first[count];     // swap positions
                first[count]++;                 // since current number's frequency will be increased, current frequency's index increased
            }    
            m[nums[i]]++;
        }
        return vector<int> (v.begin(),v.begin()+k);
    }
};