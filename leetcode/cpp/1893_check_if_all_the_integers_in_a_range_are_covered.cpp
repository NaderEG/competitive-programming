class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool res = true;
        for(int i = left; i <=right; i++) {
            bool is_i_covered = false;
            for(int j = 0; j < ranges.size(); j++) {
                if(ranges[j][0] <= i && i <= ranges[j][1]) {
                    is_i_covered = true;
                }
            }
            res = res && is_i_covered;
        }
        return res;
    }
};