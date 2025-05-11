class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = {0};
        for(int i = 1; i <= amount; i++) {
            int amt = -1;
            for(int coin : coins) {
                if(i-coin >= 0 && amt == -1 && dp[i-coin] != -1) {
                    amt = 1+dp[i-coin];
                }
                else if(i-coin >= 0 && 1 + dp[i-coin] < amt && dp[i-coin] != -1) {
                    amt = 1+dp[i-coin];
                }
            }
            dp.push_back(amt);
        }
        return dp[amount];
    }
};
