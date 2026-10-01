class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            target = max(target, nums[i]);
        }
        int res = 1;
        int longest_subarray = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] == nums[i] && nums[i] == target) {
                longest_subarray++;
                res = max(res, longest_subarray);
            } else {
                
                longest_subarray = 1;
            }
            
        }
        return res;
    }
};