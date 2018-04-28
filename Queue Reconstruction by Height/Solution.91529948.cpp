class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        if (n < 2) return people;
        sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        for (int i = 0; i < n; ++i) {
            int higher = 0;
            for (int j = 0; j < i; ++j) {
                if (people[j].first >= people[i].first) {
                    ++higher;
                }
                if (higher > people[i].second) {
                    pair<int, int> temp = people[i];
                    for (int k = i; k > j; --k) {
                        people[k] = people[k - 1];
                    }
                    people[j] = temp;
                    break;
                }
            }
        }
        return people;
    }
};