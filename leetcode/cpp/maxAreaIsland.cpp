class Solution {
public:
bool in_bounds(vector<vector<int>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int sum = 1;
        if(in_bounds(grid, i+1, j) && !visited[i+1][j] && grid[i+1][j] == 1) {
            sum +=bfs(grid, visited, i+1, j);
        }
        if(in_bounds(grid, i-1, j) && !visited[i-1][j] && grid[i-1][j] == 1) {
            sum+=bfs(grid, visited, i-1, j);
        }
        if(in_bounds(grid, i, j+1) && !visited[i][j+1] && grid[i][j+1] == 1) {
            sum+=bfs(grid, visited, i, j+1);
        }
        if(in_bounds(grid, i, j-1) && !visited[i][j-1] && grid[i][j-1] == 1) {
            sum+=bfs(grid, visited, i, j-1);
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int area = bfs(grid, visited, i, j);
                    max_area = area > max_area ? area : max_area;
                }
            }
        }
        return max_area;
    }
};
