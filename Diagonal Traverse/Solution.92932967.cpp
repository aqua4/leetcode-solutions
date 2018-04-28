class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n) {
            return {};
        }
        int m = matrix[0].size();
        if (!m) {
            return {};
        }
        vector<int> ans = {matrix[0][0]};
        int i = -1;
        int j = 2;
        if (m == 1) {
            ++i;
            --j;
        }
        while (ans.size() < n * m) {
            while (i < n - 1 && j > 0) {
                ++i;
                --j;
                ans.push_back(matrix[i][j]);
                if (ans.size() == n * m) {
                    return ans;
                }
            }
            ++i;
            if (i < n) {
                ++i;
                --j;
            }
            while (i > 0 && j < m - 1) {
                --i;
                ++j;
                ans.push_back(matrix[i][j]);
                if (ans.size() == n * m) {
                    return ans;
                }
            }
            ++j;
            if (j < m) {
                --i;
                ++j;
            }
        }
        return ans;
    }
};