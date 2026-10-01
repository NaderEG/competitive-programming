class Solution {
public:
    bool in_bounds(vector<vector<char>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        if(in_bounds(grid, i+1, j) && !visited[i+1][j] && grid[i+1][j] == '1') {
            bfs(grid, visited, i+1, j);
        }
        if(in_bounds(grid, i-1, j) && !visited[i-1][j] && grid[i-1][j] == '1') {
            bfs(grid, visited, i-1, j);
        }
        if(in_bounds(grid, i, j+1) && !visited[i][j+1] && grid[i][j+1] == '1') {
            bfs(grid, visited, i, j+1);
        }
        if(in_bounds(grid, i, j-1) && !visited[i][j-1] && grid[i][j-1] == '1') {
            bfs(grid, visited, i, j-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int num_islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
};
