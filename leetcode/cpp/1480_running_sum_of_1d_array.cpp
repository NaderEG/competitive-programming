class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int x = 0;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            x += nums[i];
            res.push_back(x);
        }
        return res;
    }
};