class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        int res = 0;
        int curr_end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < curr_end) {
                res++;
                curr_end = min(intervals[i][1], curr_end);
            } else {
                curr_end = max(intervals[i][1], curr_end);
            }
        }
        return res;
    }
};
