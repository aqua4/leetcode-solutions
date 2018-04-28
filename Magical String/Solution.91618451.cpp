class Solution {
public:
    int magicalString(int n) {
        if (n < 4) {
            return n > 0;
        }
        vector<int> v = {1, 2, 2};
        int p = 2;
        int cur = 1;
        int count = 1;
        for (int i = 3; i < n; ++i) {
            for (int j = 0; j < v[p]; ++j) {
                v.push_back(cur);
            }
            ++p;
            if (v[i] == 1) {
                ++count;
            }
            (cur == 1) ? cur = 2 : cur = 1;
        }
        return count;
    }
};