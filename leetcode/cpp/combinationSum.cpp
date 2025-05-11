class Solution {
public:
    vector<vector<int>> result;

    void sum_helper(vector<int> nums, int i, int target, int sum, vector<int> arr) {
        if(sum == target) {
            result.push_back(arr);
        }
        if(i >= nums.size() || sum >= target) {
            return;
        }
        sum_helper(nums, i+1, target, sum, arr);
        arr.push_back(nums[i]);
        sum_helper(nums, i, target, sum+nums[i], arr);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sum_helper(nums, 0, target, 0, vector<int>());
        return result;
    }
};
