class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n < 2) {
            return;
        }
        vector<vector<int> > a(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            int x = 0;
            int y = n - i - 1;
            for (int j = 0; j < n; ++j) {
                
                a[x][y] = matrix[i][j];
                //cout << x << " " << y << endl;
                ++x;
            }
        }
        matrix = a;
    }
};