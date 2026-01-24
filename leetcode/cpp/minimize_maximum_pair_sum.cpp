class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        int max_pair_sum = 0;
        while(right - left > 0) {
            max_pair_sum = max(max_pair_sum, nums[left] + nums[right]);
            left++;
            right--;
        }
        return max_pair_sum;
    }
};