class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m,num;
        vector<int> v;
        vector<int> first(n+1,0);
        for (int i=0;i<n;i++) {
            int count = m[nums[i]];
            if (!count) {
                num[nums[i]] = v.size();
                v.push_back(nums[i]);
            } else {
               // cout<<count<<" ";
                swap(v[first[count]],v[num[nums[i]]]);
                num[v[num[nums[i]]]] = num[nums[i]];
                num[nums[i]] = first[count];
              //  for (int j=0;j<v.size();j++) cout<<v[j]<<" ";
        //        cout<<endl;
          //      for (int j=0;j<v.size();j++) cout<<num[v[j]]<<" ";
            //    cout<<endl;
                first[count]++;
            }    
            m[nums[i]]++;
        }
        //for (int i=0;i<v.size();i++) cout<<m[v[i]]<<" "<<first[m[v[i]]]<<"\n";
        return vector<int> (v.begin(),v.begin()+k);
    }
};