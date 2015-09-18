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
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.start < b.start;});
        auto p = intervals.begin(), q = intervals.begin();
        for (p++; p != intervals.end(); p++) {
            if (p->start <= q->end) {
                q->end = max(q->end, p->end);
            } else {
                *(++q) = *p;
            }
        }
        intervals.erase(q + 1, intervals.end());
        return intervals;
    }
};