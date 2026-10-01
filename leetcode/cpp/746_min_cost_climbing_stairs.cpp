class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_costs = {cost[0], cost[1]};

        for(int i = 2; i <= cost.size(); i++) {
            int c = i >= cost.size() ? 0 : cost[i];
            min_costs.push_back(min(min_costs[i-1], min_costs[i-2]) + c);
        }
        return min_costs.back();
    }
};
