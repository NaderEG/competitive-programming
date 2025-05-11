class Solution {
public:
    vector<vector<int>> result;

    void subset_helper(vector<int> arr, int i, vector<int> nums) {
        if (i >= nums.size()) {
            result.push_back(arr);
            return;
        }
        subset_helper(arr, i+1, nums);
        arr.push_back(nums[i]);
        subset_helper(arr, i+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        subset_helper(vector<int>(), 0, nums);
        return result;
    }
};
