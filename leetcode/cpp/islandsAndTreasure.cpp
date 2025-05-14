class Solution {
public:
    bool valid_step(vector<vector<int>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != -1;
    }

    void bfs(vector<vector<int>>& grid, int i, int j, int distance) {
        if(distance <= grid[i][j]) {
            grid[i][j] = distance;
        } else {
            return;
        }
        distance = distance + 1;
        if(valid_step(grid, i+1, j)) {
            bfs(grid, i+1, j, distance);
        }
        if(valid_step(grid, i-1, j)) {
            bfs(grid, i-1, j, distance);
        }
        if(valid_step(grid, i, j+1)) {
            bfs(grid, i, j+1, distance);
        }
        if(valid_step(grid, i, j-1)) {
            bfs(grid, i, j-1, distance);
        }
    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    bfs(grid, i, j, 0);
                }
            }
        }
    }
};
