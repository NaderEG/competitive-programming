class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> cols(grid.size());
        vector<int> rows(grid[0].size());
        int total_servers = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    cols[i]++;
                    rows[j]++;
                    total_servers++;
                }
            }
        }
        int isolated_servers = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    if(cols[i] == 1 && rows[j] == 1) {
                        isolated_servers++;
                    }
                }
            }
        }
        return total_servers - isolated_servers;
        
    }
};