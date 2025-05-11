class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for(int k = 1; k < m; k++) {
            for (int l = 1; l < n; l++) {
                dp[k][l] = dp[k-1][l] + dp[k][l-1];
            }
        }
        return dp[m-1][n-1];
    }
};
