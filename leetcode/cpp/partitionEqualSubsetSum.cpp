class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;

        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));
        for(int i = 0; i < nums.size()+1; i++) {
            dp[i][0] = true;
        }
        for(int i = 1; i < nums.size()+1; i++) {
            for(int j = 1; j < target+1; j++) {
                if(nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[nums.size()][target];

    }
};
