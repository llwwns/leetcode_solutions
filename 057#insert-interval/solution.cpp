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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto p = lower_bound(intervals.begin(), intervals.end(), newInterval, [](const Interval& a, const Interval& b) {
            return a.end < b.start;
        });
        if (p == intervals.end()) {
            if (intervals.empty() || newInterval.start > intervals.back().end) {
                intervals.emplace_back(newInterval);
            } else {
                intervals.back().end = max (intervals.back().end, newInterval.end);
            }
        } else {
            auto q = upper_bound(p, intervals.end(), newInterval, [](const Interval& a, const Interval& b) {
                return a.end < b.start;
            });
            if (p == q) {
                intervals.insert(p, newInterval);
            } else {
                p->start = min(p->start, newInterval.start);
                p->end = max(newInterval.end, (q-1)->end);
                intervals.erase(p+1, q);
            }
        }
        return intervals;
    }
};
