class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(target < -sum || target > sum) return 0;
        
        
        map<int, vector<int>> dp;
        for(int i = -sum; i <= sum; ++i) {
            dp[i].resize(nums.size()+1, 0);
        }

        dp[0][0] = 1;

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = -sum; j <= sum; j++) {
                if(dp[j][i] != 0) {
                    if (j-nums[i] >= -sum) dp[j-nums[i]][i+1]+=dp[j][i];
                    if (j+nums[i] <= sum) dp[j+nums[i]][i+1]+=dp[j][i];
                }
                
            }
        }
        return dp[target][nums.size()];
    }
};
