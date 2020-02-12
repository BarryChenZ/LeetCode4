class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int index = 0, res = 0;
        while (index < intervals.size()) {
            int right = intervals[index][1], start = index;
            while (index < intervals.size() && intervals[index][0] < right) {
                right = min(intervals[index][1], right);
                index++;
            }
            res += index - start - 1;
        }
        return res;
    }
};
