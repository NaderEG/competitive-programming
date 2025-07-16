class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 1;
        int curr_sum = nums[left];
        int min_size = INT_MAX;
        bool solved = false;

        while(left < nums.size()) {
            if(curr_sum >= target) {
                min_size = min(min_size, right-left);
                curr_sum -= nums[left];
                left++;
                solved = true;
            } else if(right < nums.size()) {
                curr_sum += nums[right];
                right++;

            } else {
                curr_sum -= nums[left];
                left++;
            }
        }
        return solved ? min_size : 0;
    }
};