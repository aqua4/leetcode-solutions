class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> s;
        if (!nums.size()) return s;
        s.push_back(to_string(nums[0]));
        bool b=0;
        int n=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]-nums[i-1]!=1) {
                if (b) s[n]+=to_string(nums[i-1]);
                n++;
                s.push_back(to_string(nums[i]));
                b=0;
            } else {
                if (!b) {
                    b=1;
                    s[n]+="->";
                }    
            }
        } 
        if (b) s[n]+=to_string(nums[nums.size()-1]);
        return s;
    }
};