class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mini = m;
        int minj = n;
        for (int i = 0; i < ops.size(); ++i) {
            mini = min(mini, ops[i][0]);
            minj = min(minj, ops[i][1]);
        }
        return mini * minj;
    }
};