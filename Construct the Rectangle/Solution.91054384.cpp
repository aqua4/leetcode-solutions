class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;
        for (int i = (int)sqrt(area); i > 1; i--) {
            if (area % i == 0) {
                if (i < area / i) i = area / i;
                ans.push_back(i);
                ans.push_back(area / i);
                return ans;
            }
        }
        ans.push_back(area);
        ans.push_back(1);
        return ans;
    }
};