class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        vector<vector<int>> res(num_rows, vector<int>(num_cols, 0));

        for(int i = 0; i < num_rows; i++) {
            for(int j = 0; j < num_cols; j++) {
                int flat_id = i * num_cols + j;
                int rotated_id = (flat_id + k) % (num_rows*num_cols);
                res[rotated_id / num_cols][rotated_id % num_cols] = grid[i][j];
            }
        }
        return res;

    }
};