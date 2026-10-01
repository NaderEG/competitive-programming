class Solution {
public:
    bool valid_step(vector<vector<char>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 'O';
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '#';
        if(valid_step(grid, i+1, j)) {
            dfs(grid, i+1, j);
        }
        if(valid_step(grid, i-1, j)) {
            dfs(grid, i-1, j);
        }
        if(valid_step(grid, i, j+1)) {
            dfs(grid, i, j+1);
        }
        if(valid_step(grid, i, j-1)) {
            dfs(grid, i, j-1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j);
            }
        }

        for(int i = 1; i < n; i++) {
            if(board[i][m-1] == 'O') {
                dfs(board, i, m-1);
            }
        }

        for(int j = m-2; j >= 0; j--) {
            if(board[n-1][j] == 'O') {
                dfs(board, n-1, j);
            }
        }

        for(int i = n-2; i > 0; i--) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }


    }
};
