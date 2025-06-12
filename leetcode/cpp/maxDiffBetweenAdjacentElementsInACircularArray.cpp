class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff = abs(nums[0] - nums[nums.size()-1]);
        for(int i = 1; i < nums.size(); i++) {
            max_diff = max(max_diff, abs(nums[i] - nums[i-1]));
        }
        return max_diff;
    }
};