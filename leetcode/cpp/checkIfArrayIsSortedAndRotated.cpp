class Solution {
public:
    bool check(vector<int>& nums) {
        int min_num = INT_MAX;
        for(int num : nums) {
            min_num = min(min_num, num);
        }
        int min_num_pos = 0;
        for(int i = nums.size() -1; i > 0; i--) {
            if(nums[i] == min_num && nums[i-1] != min_num) {
                min_num_pos = i;
                break;
            }
        }
        for(int i = 1; i < nums.size(); i++) {
            if(nums[(min_num_pos + i) % nums.size()]  < nums[(min_num_pos + i - 1) % nums.size()]) {
                return false;
            }
        }
        return true;
    }
};