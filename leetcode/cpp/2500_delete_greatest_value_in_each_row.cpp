class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i ++) {
            sort(grid[i].begin(), grid[i].end());
        }
        int res = 0;
        for(int i = 0; i < grid[0].size(); i++) {
            int curr_max = 0;
            for(int j = 0; j < grid.size(); j++) {
                curr_max = max(grid[j][i], curr_max);
            }
            res+= curr_max;
        }
        return res;
    }
};