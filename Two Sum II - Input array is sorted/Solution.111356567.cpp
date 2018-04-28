class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p1 = 0;
        int p2 = n - 1;
        while (p1 < p2) {
            if (numbers[p1] + numbers[p2] == target) {
                vector<int> v;
                v.push_back(p1 + 1);
                v.push_back(p2 + 1);
                return v;
            }
            if (numbers[p1] + numbers[p2] > target) {
                --p2;
                continue;
            }
            ++p1;
        }
    }
};