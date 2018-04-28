class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (!numRows) return v;
        v.push_back(vector<int> {1});
        if (numRows==1) return v;
        v.push_back(vector<int> {1,1});
        for(int i=2;i<numRows;i++) {
            v.push_back(vector<int> {1});
            for(int j=1;j<v[i-1].size();j++) {
                v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v[i].push_back(1);
        }
        return v;
    }
};