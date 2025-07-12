/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(int i = 0; i < intervals.size(); ++i) {
            starts.push_back(intervals[i].start);
            ends.push_back(intervals[i].end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int s = 0; 
        int e = 0;
        int count = 0;
        int max_count = 0;

        while(s < starts.size()) {
            if(starts[s] < ends[e]) {
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            max_count = max(max_count, count);
            
        }
        return max_count;
    }
};
