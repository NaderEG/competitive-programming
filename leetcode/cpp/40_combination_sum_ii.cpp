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
        int cnt = i;
        while (nums[cnt] == nums[i]) {
            cnt++;
        }
        sum_helper(nums, cnt, target, sum, arr);
        arr.push_back(nums[i]);
        sum_helper(nums, i+1, target, sum+nums[i], arr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        sum_helper(candidates, 0, target, 0, vector<int>());
        return result;
    }
};
