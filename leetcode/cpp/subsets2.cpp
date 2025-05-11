class Solution {
public:
    vector<vector<int>> result;

    void subset_helper(vector<int> arr, int i, vector<int> nums) {
        if (i >= nums.size()) {
            result.push_back(arr);
            return;
        }

        int j = i;
        while (nums[i] == nums[j] && j < nums.size()) {
            j++;
        }
        subset_helper(arr, j, nums);
        for(; i < j; i++) {
            arr.push_back(nums[i]);
            subset_helper(arr, j, nums);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subset_helper(vector<int>(), 0, nums);
        return result;
    }
};
