class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int i = 0;
        int j = 1;
        while (j < prices.size()) {
            if(prices[i] < prices[j]) {
                max = prices[j] - prices[i] > max ? prices[j] - prices[i] : max;
                j++;
            } else {
                i = j;
                j = i+1;
            }
        }
        return max;
    }
};
