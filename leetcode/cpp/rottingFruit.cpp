class Solution {
public:
    bool valid_step(vector<vector<int>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        int total_fruit = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0) total_fruit++;
                if(grid[i][j] == 2) {
                     q.push(i*grid[0].size() + j);
                }
            }
        }


        // Time for BFS
        int time = 0;
        int rotten_fruit = 0;
        while(!q.empty()) {
            int nodesInLevel = q.size();
            for(int c = 0; c < nodesInLevel; c++) {
                int fruit = q.front();
                q.pop();
                rotten_fruit++;

                int j = fruit % grid[0].size();
                int i = fruit / grid[0].size();


                if(valid_step(grid, i+1, j)) {
                    grid[i+1][j] = 2;
                    q.push((i+1)*grid[0].size() + j);
                }
                if(valid_step(grid, i-1, j)) {
                    grid[i-1][j] = 2;
                    q.push((i-1)*grid[0].size() + j);
                }
                if(valid_step(grid, i, j+1)) {
                    grid[i][j+1] = 2;
                    q.push(i*grid[0].size() + j+1);
                }
                if(valid_step(grid, i, j-1)) {
                    grid[i][j-1] = 2;
                    q.push(i*grid[0].size() + j-1);
                }
            }
            if (!q.empty()) time++;
        }
        if(rotten_fruit == total_fruit) {
            return time;
        } else {
            return -1;
        }

    }
};
