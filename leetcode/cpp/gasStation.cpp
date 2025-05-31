class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int total = 0;
        for(int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            diff.push_back(gas[i] - cost[i]);
        }
        if(total < 0) {
            return -1;
        }
        int res = 0;
        total = 0;
        for(int i = 0; i < diff.size(); i++) {
            total += diff[i];
            if(total < 0) {
                total = 0;
                res = i+1;
            }
        }
        return res;
    }
};
