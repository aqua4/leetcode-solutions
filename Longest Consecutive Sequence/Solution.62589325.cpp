class Solution {
public:
    int findSet(int x, vector<int> &p) {
        if (p[x] == x) return x;
        return p[x] = findSet(p[x],p);
    }
    
    void unionSets(int a, int b, vector<int> &r, int &ans, vector<int> &p) {
        a = findSet(a,p);
        b = findSet(b,p);
        if (a != b) {
            if (r[a]<r[b]) swap(a,b);
            p[b] = a;
            r[a]+=r[b];
            ans = max(ans,r[a]);
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> p(n),r(n,1);
        int ans = 1;
        for (int i=0;i<n;i++) p[i]=i;
        for (int i=0;i<n;i++) {
            if (m.count(nums[i])) continue;
            m[nums[i]] = i;
            if (m.count(nums[i]+1)) {int t = m[nums[i]+1]; unionSets(t,i,r,ans,p);}
            if (m.count(nums[i]-1)) {int t = m[nums[i]-1]; unionSets(t,i,r,ans,p);}
        }
        return ans;
    }
};