class Solution {
public:
    int climbStairs(int n) {
        vector<int> possible_ways = {1, 2};
        while(possible_ways.size() < n) {
            int prev_step = possible_ways.back();
            int sec_prev_step = possible_ways.end()[-2];
            possible_ways.push_back(prev_step+sec_prev_step);
        }
        return possible_ways[n-1];
    }
};
