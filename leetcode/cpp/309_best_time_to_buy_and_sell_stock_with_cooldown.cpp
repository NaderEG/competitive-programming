class Solution {
public:
    vector<vector<int>> dp;

    int maxProfit_helper(vector<int> prices, int i, bool buying) {
        if(i >= prices.size()) {
            return 0;
        }
        if(dp[i][buying] > INT_MIN) {
            return dp[i][buying];
        }
        int cooldown = maxProfit_helper(prices, i+1, buying);
        if(buying) {
            int buy = maxProfit_helper(prices, i+1, !buying) - prices[i];
            dp[i][buying] = max(buy, cooldown);
        } else {
            int sell = maxProfit_helper(prices, i+2, !buying) + prices[i];
            dp[i][buying] = max(sell, cooldown);
        }
        return dp[i][buying];
    }

    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, INT_MIN));
        return maxProfit_helper(prices, 0, true);
    }
};
