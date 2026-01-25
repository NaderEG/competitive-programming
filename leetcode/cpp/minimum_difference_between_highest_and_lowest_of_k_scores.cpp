class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0; 
        int right = k-1;
        int min_diff = nums[right] - nums[left];
        while (right < nums.size()) {
            min_diff = min(min_diff, nums[right] - nums[left]);
            left++; 
            right++;
        }
        return min_diff;
    }
};