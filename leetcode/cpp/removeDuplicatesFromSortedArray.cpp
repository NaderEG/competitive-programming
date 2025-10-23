class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while(right < nums.size()-1) {
            while(nums[right] == nums[right+1]) {
                right++;
                if(right == nums.size()-1) {
                    nums[left] = nums[right];
                    return left+1;
                }
                
            }
            nums[left] = nums[right];
            left++;
            right++;
        }
        nums[left] = nums[right];
        return left+1;
    }
};