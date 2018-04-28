/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (!n) return intervals;
        
        vector<pair<int, int> > pintervals;
        for (int i = 0; i < n; ++i) {
            pintervals.push_back(make_pair(intervals[i].start, intervals[i].end));
        }
        sort(pintervals.begin(), pintervals.end());
        int cur_start = pintervals[0].first;
        int cur_end = pintervals[0].second;
        vector<Interval> ans;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && cur_end >= pintervals[i + 1].first) {
                cur_end = max(cur_end, pintervals[i + 1].second);
                continue;
            }
            ans.push_back(Interval(cur_start, cur_end));
            if (i + 1 < n) {
                cur_start = pintervals[i + 1].first;
                cur_end = pintervals[i + 1].second;
            }
        }
        return ans;
    }
};