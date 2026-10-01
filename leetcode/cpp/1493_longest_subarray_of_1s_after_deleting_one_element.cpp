class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int num_zeroes = nums[0] == 0;
        int max_length = 0;

        while(right < nums.size()) {
            while(num_zeroes > 1) {
                if(nums[left] == 0) {
                    num_zeroes--;
                }
                left++;
            }
            if(nums[right] == 0) {
                num_zeroes++;
            }
            right++;
            max_length = max(right-left-num_zeroes, max_length);
        }
        if(max_length == nums.size()) {
            return max_length-1;
        }
        return max_length;
    }
};